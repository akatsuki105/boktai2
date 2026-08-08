	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _08063244 @ =0x000004C7
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0806323C
	adds r4, r0, #0
_08063230:
	adds r0, r5, #0
	bl FUN_080630e8
	subs r4, #1
	cmp r4, #0
	bne _08063230
_0806323C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08063244: .4byte 0x000004C7
