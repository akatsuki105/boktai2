	push {r4, r5, r6, r7, lr}
	sub sp, #0x20
	movs r0, #0x74
	movs r1, #1
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x72
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r4, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08001864
	mov r5, sp
	b _08001858
_08001850:
	bl Script_GetValue
	stm r5!, {r0}
	adds r4, #1
_08001858:
	bl VM_GetPC
	cmp r0, #0
	beq _08001864
	cmp r4, #7
	ble _08001850
_08001864:
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r4, #0
	mov r3, sp
	bl FUN_080017d4
	add sp, #0x20
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
