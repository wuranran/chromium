// Copyright (c) 2009 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_GTK_OPTIONS_PASSWORDS_PAGE_GTK_H_
#define CHROME_BROWSER_GTK_OPTIONS_PASSWORDS_PAGE_GTK_H_

#include <gtk/gtk.h>

#include <vector>

#include "chrome/browser/password_manager/password_store.h"
#include "chrome/browser/profile.h"

class PasswordsPageGtk {
 public:
  explicit PasswordsPageGtk(Profile* profile);
  ~PasswordsPageGtk();

  GtkWidget* get_page_widget() const {
    return page_;
  }

 private:
  // Initialize the password tree widget, setting the member variables.
  void InitPasswordTree();

  // The password store associated with the currently active profile.
  PasswordStore* GetPasswordStore();

  // Sets the password list contents to the given data.
  void SetPasswordList(const std::vector<webkit_glue::PasswordForm*>& result);

  // Callback for the remove button.
  static void OnRemoveButtonClicked(GtkButton* widget, PasswordsPageGtk* page);

  // Callback for the remove all button.
  static void OnRemoveAllButtonClicked(GtkButton* widget,
                                       PasswordsPageGtk* page);

  // Callback for the remove all confirmation response.
  static void OnRemoveAllConfirmResponse(GtkDialog* confirm, gint response,
                                         PasswordsPageGtk* page);

  // Callback for the show password button.
  static void OnShowPasswordButtonClicked(GtkButton* widget,
                                          PasswordsPageGtk* page);

  // Callback for selection changed events.
  static void OnPasswordSelectionChanged(GtkTreeSelection* selection,
                                         PasswordsPageGtk* page);

  // Sorting functions.
  static gint CompareSite(GtkTreeModel* model,
                          GtkTreeIter* a, GtkTreeIter* b,
                          gpointer window);
  static gint CompareUsername(GtkTreeModel* model,
                              GtkTreeIter* a, GtkTreeIter* b,
                              gpointer window);

  // A short class to mediate requests to the password store.
  class PasswordListPopulater : public PasswordStoreConsumer {
   public:
    explicit PasswordListPopulater(PasswordsPageGtk* page) : page_(page) {
    }

    // Send a query to the password store to populate a PasswordsPageGtk.
    void populate();

    // Send the password store's reply back to the PasswordsPageGtk.
    virtual void OnPasswordStoreRequestDone(
        int handle, const std::vector<webkit_glue::PasswordForm*>& result);

   private:
    PasswordsPageGtk* page_;
    int pending_login_query_;
  };

  // Password store consumer for populating the password list.
  PasswordListPopulater populater;

  // Widgets for the buttons.
  GtkWidget* remove_button_;
  GtkWidget* remove_all_button_;
  GtkWidget* show_password_button_;

  // Widget for the shown password
  GtkWidget* password_;
  bool password_showing_;

  // Widgets for the password table.
  GtkWidget* password_tree_;
  GtkListStore* password_list_store_;
  GtkTreeModel* password_list_sort_;
  GtkTreeSelection* password_selection_;

  // The parent GtkHBox widget and GtkWindow window.
  GtkWidget* page_;

  Profile* profile_;
  std::vector<webkit_glue::PasswordForm> password_list_;

  DISALLOW_COPY_AND_ASSIGN(PasswordsPageGtk);
};

#endif  // CHROME_BROWSER_GTK_OPTIONS_PASSWORDS_PAGE_GTK_H_
