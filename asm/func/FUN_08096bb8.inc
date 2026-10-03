	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r0, _08096C14 @ =0x00003FDC
	adds r3, r4, r0
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	blt _08096C88
	ldr r1, _08096C18 @ =0x00001CEC
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _08096C1C @ =0x00001CE4
	adds r5, r4, r0
	adds r1, r4, #0
	adds r1, #0xa0
	movs r2, #0
	ldrsb r2, [r3, r2]
	ldr r3, _08096C20 @ =0x00003FE0
	adds r0, r4, r3
	adds r0, r0, r2
	movs r2, #0
	ldrsb r2, [r0, r2]
	adds r2, #0x43
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	movs r3, #1
	bl MainSprite_SetPose
	cmp r6, #0
	beq _08096C38
	ldr r1, _08096C24 @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08096C2C
	ldr r1, _08096C28 @ =0x000002DF
	b _08096C30
	.align 2, 0
_08096C14: .4byte 0x00003FDC
_08096C18: .4byte 0x00001CEC
_08096C1C: .4byte 0x00001CE4
_08096C20: .4byte 0x00003FE0
_08096C24: .4byte 0x00003AE8
_08096C28: .4byte 0x000002DF
_08096C2C:
	movs r1, #0xb8
	lsls r1, r1, #2
_08096C30:
	adds r0, r5, #0
	bl FUN_0808ba0c
	b _08096C40
_08096C38:
	ldr r1, _08096C74 @ =0x000002DF
	adds r0, r5, #0
	bl FUN_0808ba0c
_08096C40:
	ldr r3, _08096C78 @ =0x00001ECC
	adds r2, r4, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _08096C7C @ =0x00001EE4
	adds r2, r4, r0
	ldr r1, _08096C80 @ =0x00003FDC
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r1, #0x11
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r4, r0
	ldr r3, _08096C84 @ =0x00000F84
	adds r0, r0, r3
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	b _08096C9E
	.align 2, 0
_08096C74: .4byte 0x000002DF
_08096C78: .4byte 0x00001ECC
_08096C7C: .4byte 0x00001EE4
_08096C80: .4byte 0x00003FDC
_08096C84: .4byte 0x00000F84
_08096C88:
	ldr r0, _08096CA4 @ =0x00001CEC
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r3, _08096CA8 @ =0x00001ECC
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08096C9E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08096CA4: .4byte 0x00001CEC
_08096CA8: .4byte 0x00001ECC
