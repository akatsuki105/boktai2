	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r6, #0
	ldr r0, _081D6364 @ =0x0000057C
	adds r0, r0, r7
	mov r8, r0
	movs r2, #1
	rsbs r2, r2, #0
	mov sb, r2
_081D6350:
	movs r1, #1
	lsls r1, r6
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D6368
	movs r0, #1
	b _081D636A
	.align 2, 0
_081D6364: .4byte 0x0000057C
_081D6368:
	movs r0, #0
_081D636A:
	cmp r0, #0
	beq _081D63A0
	movs r0, #0xac
	lsls r0, r0, #1
	muls r0, r6, r0
	adds r0, #0x1c
	adds r4, r7, r0
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0x58
	bl Hitbox_Unregister
	movs r0, #0xa7
	lsls r0, r0, #1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, sb
	beq _081D63A0
	adds r0, r4, #0
	adds r0, #0xa8
	bl AuxShadow_Remove
	movs r0, #0xff
	strb r0, [r5]
_081D63A0:
	adds r6, #1
	cmp r6, #3
	ble _081D6350
	ldr r1, _081D63B8 @ =0x03000198
	movs r0, #0
	str r0, [r1]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D63B8: .4byte 0x03000198
