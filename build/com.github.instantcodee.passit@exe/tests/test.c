/* test.c generated by valac 0.36.16, the Vala compiler
 * generated from test.vala, do not modify */

/*
* Copyright (C) 2018  Mondei1 <klier.nicolas@gmx.de>
* 
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <gobject/gvaluecollector.h>


#define APP_TESTS_TYPE_TESTING (app_tests_testing_get_type ())
#define APP_TESTS_TESTING(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), APP_TESTS_TYPE_TESTING, AppTestsTesting))
#define APP_TESTS_TESTING_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), APP_TESTS_TYPE_TESTING, AppTestsTestingClass))
#define APP_TESTS_IS_TESTING(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), APP_TESTS_TYPE_TESTING))
#define APP_TESTS_IS_TESTING_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), APP_TESTS_TYPE_TESTING))
#define APP_TESTS_TESTING_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), APP_TESTS_TYPE_TESTING, AppTestsTestingClass))

typedef struct _AppTestsTesting AppTestsTesting;
typedef struct _AppTestsTestingClass AppTestsTestingClass;
typedef struct _AppTestsTestingPrivate AppTestsTestingPrivate;
typedef struct _AppTestsParamSpecTesting AppTestsParamSpecTesting;

struct _AppTestsTesting {
	GTypeInstance parent_instance;
	volatile int ref_count;
	AppTestsTestingPrivate * priv;
};

struct _AppTestsTestingClass {
	GTypeClass parent_class;
	void (*finalize) (AppTestsTesting *self);
};

struct _AppTestsParamSpecTesting {
	GParamSpec parent_instance;
};


static gpointer app_tests_testing_parent_class = NULL;

gpointer app_tests_testing_ref (gpointer instance);
void app_tests_testing_unref (gpointer instance);
GParamSpec* app_tests_param_spec_testing (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void app_tests_value_set_testing (GValue* value, gpointer v_object);
void app_tests_value_take_testing (GValue* value, gpointer v_object);
gpointer app_tests_value_get_testing (const GValue* value);
GType app_tests_testing_get_type (void) G_GNUC_CONST;
enum  {
	APP_TESTS_TESTING_0_PROPERTY
};
AppTestsTesting* app_tests_testing_new (gchar** args, int args_length1);
AppTestsTesting* app_tests_testing_construct (GType object_type, gchar** args, int args_length1);
static void __lambda8_ (AppTestsTesting* self);
void app_tests_assert_string_compare (const gchar* expected, const gchar* actual, const gchar* compare);
void app_tests_assert_bool_compare (gboolean* expected, gboolean* actual, const gchar* compare);
void app_tests_assert_true (gboolean* expected);
void app_tests_assert_false (gboolean* expected);
void app_tests_assert_int_compare (gint* expected, gint* actual, const gchar* compare);
void app_tests_assert_float_compare (gfloat* expected, gfloat* actual, const gchar* compare);
void app_tests_assert_double_compare (gdouble* expected, gdouble* actual, const gchar* compare);
static void ___lambda8__gtest_data_func (gpointer self);
void app_tests_testing_run (AppTestsTesting* self);
static void app_tests_testing_finalize (AppTestsTesting * obj);


static void __lambda8_ (AppTestsTesting* self) {
	gboolean _tmp0_;
	gboolean _tmp1_;
	gboolean _tmp2_;
	gboolean _tmp3_;
	gint _tmp4_;
	gint _tmp5_;
	gfloat _tmp6_;
	gfloat _tmp7_;
	gdouble _tmp8_;
	gdouble _tmp9_;
#line 31 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	app_tests_assert_string_compare ("Test", "Test", "==");
#line 32 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	_tmp0_ = TRUE;
#line 32 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	_tmp1_ = TRUE;
#line 32 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	app_tests_assert_bool_compare (&_tmp0_, &_tmp1_, "==");
#line 33 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	_tmp2_ = TRUE;
#line 33 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	app_tests_assert_true (&_tmp2_);
#line 34 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	_tmp3_ = FALSE;
#line 34 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	app_tests_assert_false (&_tmp3_);
#line 35 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	_tmp4_ = 5;
#line 35 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	_tmp5_ = 5;
#line 35 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	app_tests_assert_int_compare (&_tmp4_, &_tmp5_, "==");
#line 36 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	_tmp6_ = 5.2f;
#line 36 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	_tmp7_ = 6.4f;
#line 36 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	app_tests_assert_float_compare (&_tmp6_, &_tmp7_, "!=");
#line 37 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	_tmp8_ = 8.8;
#line 37 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	_tmp9_ = 8.8;
#line 37 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	app_tests_assert_double_compare (&_tmp8_, &_tmp9_, "<=");
#line 131 "test.c"
}


static void ___lambda8__gtest_data_func (gpointer self) {
#line 30 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	__lambda8_ ((AppTestsTesting*) self);
#line 30 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	app_tests_testing_unref (self);
#line 140 "test.c"
}


AppTestsTesting* app_tests_testing_construct (GType object_type, gchar** args, int args_length1) {
	AppTestsTesting* self = NULL;
#line 26 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	self = (AppTestsTesting*) g_type_create_instance (object_type);
#line 27 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	g_test_init (&args_length1, &args, NULL);
#line 30 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	g_test_add_data_func ("/init", app_tests_testing_ref (self), ___lambda8__gtest_data_func);
#line 26 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	return self;
#line 154 "test.c"
}


AppTestsTesting* app_tests_testing_new (gchar** args, int args_length1) {
#line 26 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	return app_tests_testing_construct (APP_TESTS_TYPE_TESTING, args, args_length1);
#line 161 "test.c"
}


void app_tests_testing_run (AppTestsTesting* self) {
#line 41 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	g_return_if_fail (self != NULL);
#line 42 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	g_test_run ();
#line 170 "test.c"
}


static void app_tests_value_testing_init (GValue* value) {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	value->data[0].v_pointer = NULL;
#line 177 "test.c"
}


static void app_tests_value_testing_free_value (GValue* value) {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	if (value->data[0].v_pointer) {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		app_tests_testing_unref (value->data[0].v_pointer);
#line 186 "test.c"
	}
}


static void app_tests_value_testing_copy_value (const GValue* src_value, GValue* dest_value) {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	if (src_value->data[0].v_pointer) {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		dest_value->data[0].v_pointer = app_tests_testing_ref (src_value->data[0].v_pointer);
#line 196 "test.c"
	} else {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		dest_value->data[0].v_pointer = NULL;
#line 200 "test.c"
	}
}


static gpointer app_tests_value_testing_peek_pointer (const GValue* value) {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	return value->data[0].v_pointer;
#line 208 "test.c"
}


static gchar* app_tests_value_testing_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	if (collect_values[0].v_pointer) {
#line 215 "test.c"
		AppTestsTesting * object;
		object = collect_values[0].v_pointer;
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		if (object->parent_instance.g_class == NULL) {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
#line 222 "test.c"
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
#line 226 "test.c"
		}
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		value->data[0].v_pointer = app_tests_testing_ref (object);
#line 230 "test.c"
	} else {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		value->data[0].v_pointer = NULL;
#line 234 "test.c"
	}
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	return NULL;
#line 238 "test.c"
}


static gchar* app_tests_value_testing_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	AppTestsTesting ** object_p;
	object_p = collect_values[0].v_pointer;
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	if (!object_p) {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
#line 249 "test.c"
	}
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	if (!value->data[0].v_pointer) {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		*object_p = NULL;
#line 255 "test.c"
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		*object_p = value->data[0].v_pointer;
#line 259 "test.c"
	} else {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		*object_p = app_tests_testing_ref (value->data[0].v_pointer);
#line 263 "test.c"
	}
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	return NULL;
#line 267 "test.c"
}


GParamSpec* app_tests_param_spec_testing (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	AppTestsParamSpecTesting* spec;
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	g_return_val_if_fail (g_type_is_a (object_type, APP_TESTS_TYPE_TESTING), NULL);
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	G_PARAM_SPEC (spec)->value_type = object_type;
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	return G_PARAM_SPEC (spec);
#line 281 "test.c"
}


gpointer app_tests_value_get_testing (const GValue* value) {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, APP_TESTS_TYPE_TESTING), NULL);
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	return value->data[0].v_pointer;
#line 290 "test.c"
}


void app_tests_value_set_testing (GValue* value, gpointer v_object) {
	AppTestsTesting * old;
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, APP_TESTS_TYPE_TESTING));
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	old = value->data[0].v_pointer;
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	if (v_object) {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, APP_TESTS_TYPE_TESTING));
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		value->data[0].v_pointer = v_object;
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		app_tests_testing_ref (value->data[0].v_pointer);
#line 310 "test.c"
	} else {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		value->data[0].v_pointer = NULL;
#line 314 "test.c"
	}
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	if (old) {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		app_tests_testing_unref (old);
#line 320 "test.c"
	}
}


void app_tests_value_take_testing (GValue* value, gpointer v_object) {
	AppTestsTesting * old;
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, APP_TESTS_TYPE_TESTING));
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	old = value->data[0].v_pointer;
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	if (v_object) {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, APP_TESTS_TYPE_TESTING));
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		value->data[0].v_pointer = v_object;
#line 339 "test.c"
	} else {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		value->data[0].v_pointer = NULL;
#line 343 "test.c"
	}
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	if (old) {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		app_tests_testing_unref (old);
#line 349 "test.c"
	}
}


static void app_tests_testing_class_init (AppTestsTestingClass * klass) {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	app_tests_testing_parent_class = g_type_class_peek_parent (klass);
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	((AppTestsTestingClass *) klass)->finalize = app_tests_testing_finalize;
#line 359 "test.c"
}


static void app_tests_testing_instance_init (AppTestsTesting * self) {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	self->ref_count = 1;
#line 366 "test.c"
}


static void app_tests_testing_finalize (AppTestsTesting * obj) {
	AppTestsTesting * self;
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, APP_TESTS_TYPE_TESTING, AppTestsTesting);
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	g_signal_handlers_destroy (self);
#line 376 "test.c"
}


/**
     * The {@code Testing} class is entry point for unit and UI testing for the application
     *
     * @since 1.0.0
     */
GType app_tests_testing_get_type (void) {
	static volatile gsize app_tests_testing_type_id__volatile = 0;
	if (g_once_init_enter (&app_tests_testing_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { app_tests_value_testing_init, app_tests_value_testing_free_value, app_tests_value_testing_copy_value, app_tests_value_testing_peek_pointer, "p", app_tests_value_testing_collect_value, "p", app_tests_value_testing_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (AppTestsTestingClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) app_tests_testing_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (AppTestsTesting), 0, (GInstanceInitFunc) app_tests_testing_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType app_tests_testing_type_id;
		app_tests_testing_type_id = g_type_register_fundamental (g_type_fundamental_next (), "AppTestsTesting", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&app_tests_testing_type_id__volatile, app_tests_testing_type_id);
	}
	return app_tests_testing_type_id__volatile;
}


gpointer app_tests_testing_ref (gpointer instance) {
	AppTestsTesting * self;
	self = instance;
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	g_atomic_int_inc (&self->ref_count);
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	return instance;
#line 406 "test.c"
}


void app_tests_testing_unref (gpointer instance) {
	AppTestsTesting * self;
	self = instance;
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		APP_TESTS_TESTING_GET_CLASS (self)->finalize (self);
#line 25 "/home/mondei1/Dokumente/Workspace/ElementaryApps/PassIt/tests/test.vala"
		g_type_free_instance ((GTypeInstance *) self);
#line 419 "test.c"
	}
}



