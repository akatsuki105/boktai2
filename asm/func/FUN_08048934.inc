	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	movs r0, #0x82
	lsls r0, r0, #1
	adds r2, r3, r0
	ldrb r0, [r2]
	cmp r0, #6
	bhi _0804895A
	ldr r1, _08048960 @ =0x00000105
	adds r0, r3, r1
	ldrb r1, [r2]
	adds r0, r0, r1
	ldrb r1, [r3, #7]
	strb r1, [r0]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	strb r4, [r3, #7]
_0804895A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08048960: .4byte 0x00000105
