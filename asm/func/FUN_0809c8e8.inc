	push {lr}
	adds r2, r0, #0
	ldr r0, _0809C91C @ =0x030044BC
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0809C914
	ldr r1, _0809C920 @ =0x000009DF
	adds r0, r2, r1
	ldrb r0, [r0]
	ldr r1, _0809C924 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r3, #0x9e
	lsls r3, r3, #4
	adds r0, r2, r3
	str r1, [r0]
	adds r0, r2, #0
	bl FUN_0809c880
_0809C914:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_0809C91C: .4byte 0x030044BC
_0809C920: .4byte 0x000009DF
_0809C924: .4byte 0x03002BE0
