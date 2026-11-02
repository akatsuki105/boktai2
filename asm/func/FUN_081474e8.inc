	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08147500 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08147504
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08147506
	.align 2, 0
_08147500: .4byte 0x0000046D
_08147504:
	movs r0, #0
_08147506:
	cmp r0, #0
	beq _08147528
	ldrb r0, [r4, #5]
	bl FUN_08148750
	adds r2, r0, #0
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080efb60
	movs r0, #0x97
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_08147528:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
