	push {r4, r5, lr}
	lsls r2, r0, #1
	ldr r0, _0804B528 @ =0x085AB5B0
	ldr r5, _0804B52C @ =gSystemSaveData
	adds r3, r2, r0
	movs r4, #1
_0804B50C:
	ldrb r1, [r3]
	ldr r0, [r5]
	adds r0, #0x18
	adds r0, r0, r2
	strb r1, [r0]
	adds r3, #1
	subs r4, #1
	adds r2, #1
	cmp r4, #0
	bge _0804B50C
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0804B528: .4byte 0x085AB5B0
_0804B52C: .4byte gSystemSaveData
