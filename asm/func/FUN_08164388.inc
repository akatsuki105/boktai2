	push {r4, r5, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r4, [r0]
	ldr r2, _081643E0 @ =0x00000482
	adds r1, r3, r2
	movs r0, #1
	strh r0, [r1]
	movs r5, #8
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r0, [r0]
	ands r0, r5
	cmp r0, #0
	beq _081643DC
	movs r2, #0xa
	ldrsh r1, [r3, r2]
	ldr r0, _081643E4 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x2e
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _081643C0
	rsbs r1, r1, #0
_081643C0:
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r1, r0
	bgt _081643DC
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bls _081643E8
_081643DC:
	movs r0, #0
	b _08164466
	.align 2, 0
_081643E0: .4byte 0x00000482
_081643E4: .4byte 0x03002BE0
_081643E8:
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _0816440C @ =0x00000546
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r1, r0
	blt _0816441A
	ldr r1, _08164410 @ =0x0000068E
	adds r0, r4, r1
	ldrh r0, [r0]
	ands r0, r5
	cmp r0, #0
	beq _08164414
	movs r0, #1
	b _08164416
	.align 2, 0
_0816440C: .4byte 0x00000546
_08164410: .4byte 0x0000068E
_08164414:
	movs r0, #0
_08164416:
	cmp r0, #0
	beq _08164454
_0816441A:
	movs r0, #0x80
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r3, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0x14
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _08164450 @ =0x00000482
	adds r1, r3, r2
	movs r0, #2
	strh r0, [r1]
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _08164464
	.align 2, 0
_08164450: .4byte 0x00000482
_08164454:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r3, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08164464:
	movs r0, #1
_08164466:
	pop {r4, r5}
	pop {r1}
	bx r1
