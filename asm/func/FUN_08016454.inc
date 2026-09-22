	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08016482
	movs r2, #0
	strb r2, [r4, #1]
	ldr r0, [r4, #0x3c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x3c]
	adds r0, r4, #0
	adds r0, #0x68
	ldr r1, _08016498 @ =0x03002B44
	ldr r1, [r1]
	ldr r1, [r1, #0x18]
	str r2, [sp]
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
_08016482:
	movs r1, #0x16
	ldrsh r0, [r4, r1]
	cmp r0, #0
	ble _08016490
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _0801649C
_08016490:
	movs r0, #1
	strb r0, [r4, #5]
	b _080164C8
	.align 2, 0
_08016498: .4byte 0x03002B44
_0801649C:
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _080164AC
	adds r1, r4, #0
	adds r1, #0xc
	movs r2, #0
	bl Hitbox_SetPos
_080164AC:
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _080164C2
	adds r1, r4, #0
	adds r1, #0xc
	movs r2, #0
	bl Hitbox_SetPos
	ldr r0, [r4, #0x1c]
	bl Hitbox_Register
_080164C2:
	ldrh r0, [r4, #6]
	adds r0, #1
	strh r0, [r4, #6]
_080164C8:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
