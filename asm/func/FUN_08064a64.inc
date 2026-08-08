	push {r4, lr}
	adds r4, r0, #0
	adds r2, r1, #0
	cmp r2, #0
	bne _08064A90
	movs r0, #0x99
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, _08064A88 @ =0x0000FFFF
	strh r0, [r1]
	ldr r1, _08064A8C @ =0x00000266
	adds r0, r4, r1
	strh r2, [r0]
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r0, r4, r3
	strh r2, [r0]
	b _08064AAA
	.align 2, 0
_08064A88: .4byte 0x0000FFFF
_08064A8C: .4byte 0x00000266
_08064A90:
	ldrb r1, [r2]
	movs r3, #0x99
	lsls r3, r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	ldrb r1, [r2, #1]
	adds r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	ldrb r1, [r2, #2]
	adds r3, #2
	adds r0, r4, r3
	strh r1, [r0]
_08064AAA:
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0806483c
	adds r0, r4, #0
	bl FUN_080612bc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
