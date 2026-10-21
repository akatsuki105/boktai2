	push {lr}
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _08065ACA
	movs r1, #0x18
	ldr r0, _08065AB8 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08065ABC @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08065AC0
	movs r0, #1
	b _08065AC2
	.align 2, 0
_08065AB8: .4byte 0x030046A0
_08065ABC: .4byte 0x00000934
_08065AC0:
	movs r0, #0
_08065AC2:
	cmp r0, #0
	bne _08065ACA
	movs r0, #1
	b _08065ACC
_08065ACA:
	movs r0, #0
_08065ACC:
	pop {r1}
	bx r1
