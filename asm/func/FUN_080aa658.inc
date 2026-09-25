	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r0, _080AA6A4 @ =0x0000034A
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _080AA692
	ldr r2, _080AA6A8 @ =0x030044BC
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x67
	bl PlaySound_082406e0
	movs r0, #0x1f
	str r0, [sp]
	ldr r0, _080AA6AC @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #4
	movs r2, #0x1f
	movs r3, #0x1f
	bl FUN_0823ce68
_080AA692:
	ldrh r0, [r5]
	cmp r0, #5
	bhi _080AA6B0
	adds r0, r4, #0
	adds r0, #0x94
	bl Hitbox_Register
	b _080AA6C0
	.align 2, 0
_080AA6A4: .4byte 0x0000034A
_080AA6A8: .4byte 0x030044BC
_080AA6AC: .4byte 0x00001FFF
_080AA6B0:
	cmp r0, #6
	bne _080AA6C0
	ldr r0, _080AA6DC @ =0x030047A4
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_080AA6C0:
	ldr r0, _080AA6E0 @ =0x0000034A
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2f
	bls _080AA6E4
	adds r0, r4, #0
	bl KillEntity
	b _080AA6FE
	.align 2, 0
_080AA6DC: .4byte 0x030047A4
_080AA6E0: .4byte 0x0000034A
_080AA6E4:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _080AA6F4
	movs r0, #0x20
	bl FUN_0823b9cc
	b _080AA6FE
_080AA6F4:
	ldrh r1, [r2]
	movs r0, #0x30
	subs r0, r0, r1
	bl FUN_0823b9cc
_080AA6FE:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
