	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r2, #0
	ldr r0, _08234918 @ =0x030046A4
	ldr r0, [r0]
	ldr r1, [r0, #0xc]
	ldrb r0, [r1]
	cmp r2, r0
	bge _08234924
	adds r3, r0, #0
_0823490E:
	ldrh r0, [r1, #0xe]
	cmp r0, r4
	bne _0823491C
	movs r0, #1
	b _08234926
	.align 2, 0
_08234918: .4byte 0x030046A4
_0823491C:
	adds r1, #0xc
	adds r2, #1
	cmp r2, r3
	blt _0823490E
_08234924:
	movs r0, #0
_08234926:
	pop {r4}
	pop {r1}
	bx r1
