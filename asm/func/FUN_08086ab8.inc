	push {lr}
	ldr r0, _08086AE0 @ =0x03002C00
	ldr r1, [r0]
	cmp r1, #0
	beq _08086AE8
	ldrb r0, [r1, #0x1a]
	cmp r0, #4
	bne _08086AE8
	ldr r2, _08086AE4 @ =0x000001F5
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #4
	bhi _08086AE8
	adds r0, r1, #0
	movs r1, #9
	bl Coffin_SetState
	movs r0, #1
	b _08086AEA
	.align 2, 0
_08086AE0: .4byte 0x03002C00
_08086AE4: .4byte 0x000001F5
_08086AE8:
	movs r0, #0
_08086AEA:
	pop {r1}
	bx r1
	.align 2, 0
