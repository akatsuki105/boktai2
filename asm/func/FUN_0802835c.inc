	push {lr}
	adds r1, r0, #0
	movs r2, #0x82
	lsls r2, r2, #4
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	bne _08028376
	ldr r2, _0802837C @ =0x00000893
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _08028380
_08028376:
	movs r0, #0
	b _08028382
	.align 2, 0
_0802837C: .4byte 0x00000893
_08028380:
	movs r0, #1
_08028382:
	pop {r1}
	bx r1
	.align 2, 0
