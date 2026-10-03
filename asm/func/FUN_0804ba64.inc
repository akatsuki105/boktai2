	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0
	strb r0, [r5, #0x1c]
	strb r0, [r5, #0x19]
	strb r0, [r5, #0x1a]
	strb r0, [r5, #0x1e]
	strb r0, [r5, #0x1f]
	adds r1, r5, #0
	adds r1, #0x20
	strb r0, [r1]
	adds r1, #1
	strb r0, [r1]
	movs r1, #0
	strh r0, [r5, #0x22]
	adds r0, r5, #0
	adds r0, #0x24
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r6, _0804BB2C @ =0x030000DC
	movs r2, #0
	movs r1, #7
	adds r0, #8
_0804BA9C:
	strb r2, [r0]
	subs r0, #1
	subs r1, #1
	cmp r1, #0
	bge _0804BA9C
	adds r0, r5, #0
	adds r0, #0x30
	movs r2, #0
	movs r3, #1
	strb r3, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r4, r5, #0
	adds r4, #0x34
	strb r2, [r4]
	adds r0, #4
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	strb r2, [r5, #0x1c]
	movs r1, #0
	strh r2, [r5, #0x38]
	str r2, [r5, #0x44]
	subs r0, #4
	strb r3, [r0]
	strh r2, [r5, #0x3a]
	adds r0, #0xa
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strh r2, [r0]
	adds r0, #2
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	str r2, [r5, #0x48]
	strb r1, [r6]
	adds r0, #0xb8
	strb r1, [r0]
	strb r1, [r4]
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r5, r1
	str r2, [r0]
	adds r1, #4
	adds r0, r5, r1
	str r2, [r0]
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0x40
	bl ClearMemory
	adds r0, r5, #0
	adds r0, #0xa4
	movs r1, #4
	bl ClearMemory
	adds r0, r5, #0
	adds r0, #0xa8
	movs r1, #0x10
	bl ClearMemory
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804BB2C: .4byte 0x030000DC
