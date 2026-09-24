	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r7, #0
	ldr r1, _081EAA8C @ =0x0000052C
	adds r1, r1, r0
	mov sb, r1
	adds r6, r0, #0
	adds r6, #0x9c
	movs r2, #0xba
	lsls r2, r2, #1
	adds r5, r0, r2
	adds r4, r0, #0
	adds r4, #0x3c
	movs r0, #1
	mov r8, r0
_081EAA7A:
	mov r1, r8
	lsls r1, r7
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081EAA90
	movs r0, #1
	b _081EAA92
	.align 2, 0
_081EAA8C: .4byte 0x0000052C
_081EAA90:
	movs r0, #0
_081EAA92:
	cmp r0, #0
	beq _081EAAB4
	adds r0, r4, #0
	bl MainSprite_Remove
	ldrh r1, [r5]
	mov r0, r8
	ands r0, r1
	cmp r0, #0
	beq _081EAAAC
	adds r0, r6, #0
	bl FUN_08002a58
_081EAAAC:
	adds r0, r4, #0
	adds r0, #0x60
	bl FUN_0823b284
_081EAAB4:
	movs r0, #0x9e
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r5, r5, r0
	adds r4, r4, r0
	adds r7, #1
	cmp r7, #3
	ble _081EAA7A
	movs r1, #0
	ldr r0, _081EAAD8 @ =0x030001C0
	str r1, [r0]
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EAAD8: .4byte 0x030001C0
