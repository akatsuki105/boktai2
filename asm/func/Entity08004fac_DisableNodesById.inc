	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, _08004E60 @ =0x03000024
	ldr r0, [r0]
	cmp r0, #0
	bne _08004E64
	movs r0, #1
	rsbs r0, r0, #0
	b _08004E8C
	.align 2, 0
_08004E60: .4byte 0x03000024
_08004E64:
	ldr r1, [r0, #0x18]
	cmp r1, #0
	beq _08004E8A
_08004E6A:
	ldr r4, [r1, #0x20]
	ldrh r0, [r1]
	cmp r0, r5
	bne _08004E84
	ldrb r0, [r1, #2]
	cmp r0, #0
	beq _08004E84
	movs r0, #0
	strb r0, [r1, #2]
	adds r0, r1, #0
	adds r0, #0xc
	bl FUN_082342a8
_08004E84:
	adds r1, r4, #0
	cmp r1, #0
	bne _08004E6A
_08004E8A:
	movs r0, #0
_08004E8C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
