	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, _0821BF2C @ =0x00000BC4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x50
	mov r5, sp
	adds r5, #2
	mov r2, sp
	adds r3, r5, #0
	bl FUN_0821bd5c
	ldr r0, _0821BF30 @ =0x00000BD4
	adds r1, r4, r0
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #8
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #4
	adds r4, r4, r1
	ldrh r0, [r5]
	lsls r0, r0, #8
	str r0, [r4]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0821BF2C: .4byte 0x00000BC4
_0821BF30: .4byte 0x00000BD4
