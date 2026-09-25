	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x44]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x44]
	adds r3, r4, #0
	adds r3, #0xee
	ldrh r0, [r3]
	cmp r0, #0
	bne _0807FDD6
	ldr r2, _0807FDF0 @ =0x030044BC
	subs r1, #6
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _0807FDF4 @ =0x030047A4
	ldr r0, [r2]
	adds r1, #3
	ands r0, r1
	str r0, [r2]
_0807FDD6:
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _0807FDF8
	adds r0, r4, #0
	adds r0, #0x9c
	bl Hitbox_Register
	b _0807FDFE
	.align 2, 0
_0807FDF0: .4byte 0x030044BC
_0807FDF4: .4byte 0x030047A4
_0807FDF8:
	adds r0, r4, #0
	bl KillEntity
_0807FDFE:
	pop {r4}
	pop {r0}
	bx r0
