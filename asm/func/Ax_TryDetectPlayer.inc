	push {r4, lr}
	adds r4, r0, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0819E874
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	ldr r0, _0819E878 @ =0x00000F14
	adds r2, r2, r0
	ldr r0, _0819E87C @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0819E874
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blo _0819E880
_0819E874:
	movs r0, #0
	b _0819E882
	.align 2, 0
_0819E878: .4byte 0x00000F14
_0819E87C: .4byte 0x03002BE0
_0819E880:
	movs r0, #1
_0819E882:
	pop {r4}
	pop {r1}
	bx r1
