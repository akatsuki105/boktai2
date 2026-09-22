	push {r4, r5, r6, lr}
	bl Script_GetValue
	adds r6, r0, #0
	bl FUN_0823d340
	adds r5, r0, #0
	cmp r5, #0
	beq _08047CDC
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	adds r4, r0, #0
	adds r0, r5, #0
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	adds r1, r0, #0
	adds r0, r6, #0
	bl TextBox_SetExtendValue
	movs r0, #0
	b _08047CE0
_08047CDC:
	movs r0, #1
	rsbs r0, r0, #0
_08047CE0:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
