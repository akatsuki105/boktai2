	push {r4, r5, r6, lr}
	sub sp, #0x20
	movs r0, #0x72
	movs r1, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r4, #0
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080020EE
	mov r5, sp
	b _080020E2
_080020DA:
	bl Script_GetValue
	stm r5!, {r0}
	adds r4, #1
_080020E2:
	bl VM_GetPC
	cmp r0, #0
	beq _080020EE
	cmp r4, #7
	ble _080020DA
_080020EE:
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sp
	bl FUN_0800205c
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
