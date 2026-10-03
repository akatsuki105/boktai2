	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08099E68 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08099E60
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08099c64
	movs r0, #6
	bl FUN_08099b3c
	adds r0, r4, #0
	bl FUN_0808c700
	ldr r1, _08099E6C @ =FUN_08099e70
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_08099E60:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08099E68: .4byte 0x030044E0
_08099E6C: .4byte FUN_08099e70
