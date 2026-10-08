	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	bl FUN_0808c434
	cmp r0, #0
	beq _08093E30
	ldr r0, _08093E38 @ =0x000009EE
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _08093E30
	ldr r1, _08093E3C @ =0x000020AC
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08093E40 @ =0x00003AEE
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_08091e64
	ldr r1, _08093E44 @ =FUN_08093e4c
	adds r0, r4, #0
	movs r2, #1
	bl EntityCC28_SetState
	ldr r0, _08093E48 @ =0x0000010D
	bl PlaySound_082406e0
_08093E30:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08093E38: .4byte 0x000009EE
_08093E3C: .4byte 0x000020AC
_08093E40: .4byte 0x00003AEE
_08093E44: .4byte FUN_08093e4c
_08093E48: .4byte 0x0000010D
