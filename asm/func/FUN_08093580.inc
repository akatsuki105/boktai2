	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0
	bl FUN_0808c434
	cmp r0, #0
	beq _080935FE
	ldr r0, _080935DC @ =0x000009EE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080935FE
	ldr r1, _080935E0 @ =0x000020AC
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r4, _080935E4 @ =0x00000121
	adds r0, r5, #0
	bl FUN_0808ba64
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r3, #0x10
	bl FUN_0808c164
	ldr r0, _080935E8 @ =0x0000010D
	bl PlaySound_082406e0
	ldr r1, _080935EC @ =0x00003F9D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080935F4
	ldr r1, _080935F0 @ =FUN_08093710
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
	b _080935FE
	.align 2, 0
_080935DC: .4byte 0x000009EE
_080935E0: .4byte 0x000020AC
_080935E4: .4byte 0x00000121
_080935E8: .4byte 0x0000010D
_080935EC: .4byte 0x00003F9D
_080935F0: .4byte FUN_08093710
_080935F4:
	ldr r1, _08093604 @ =FUN_08093608
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
_080935FE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08093604: .4byte FUN_08093608
