	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r6, _08011174 @ =0x0000FFFF
	movs r5, #0
	adds r1, r7, #0
	adds r1, #0x88
	ldr r0, [r1]
	adds r0, #4
	cmp r5, r0
	bhs _0801114C
	adds r4, r1, #0
_0801113A:
	adds r0, r7, #0
	bl FUN_08011110
	eors r6, r0
	adds r5, #1
	ldr r0, [r4]
	adds r0, #4
	cmp r5, r0
	blo _0801113A
_0801114C:
	adds r4, r7, #4
	movs r5, #0x13
_08011150:
	ldrb r1, [r4]
	adds r0, r6, #0
	eors r0, r1
	movs r1, #0x3f
	ands r0, r1
	strb r0, [r4]
	adds r0, r7, #0
	bl FUN_08011110
	eors r6, r0
	adds r4, #1
	subs r5, #1
	cmp r5, #0
	bge _08011150
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08011174: .4byte 0x0000FFFF
