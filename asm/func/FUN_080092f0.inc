	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #4]
	cmp r0, #1
	beq _0800935C
	ldrb r0, [r4, #5]
	cmp r0, #1
	beq _08009330
	cmp r0, #1
	bgt _0800930A
	cmp r0, #0
	beq _08009310
	b _0800935C
_0800930A:
	cmp r0, #2
	beq _08009350
	b _0800935C
_08009310:
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _08009320
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08009278
	b _0800935C
_08009320:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08009278
	ldrb r0, [r4, #7]
	subs r0, #1
	strb r0, [r4, #7]
	b _0800935C
_08009330:
	ldrb r0, [r4, #7]
	cmp r0, #4
	bls _08009340
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08009278
	b _0800935C
_08009340:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08009278
	ldrb r0, [r4, #7]
	adds r0, #1
	strb r0, [r4, #7]
	b _0800935C
_08009350:
	movs r0, #5
	strb r0, [r4, #7]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08009278
_0800935C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
