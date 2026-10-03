	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0
	bl FUN_0808c434
	cmp r0, #0
	beq _08093974
	ldr r0, _08093924 @ =0x000009EE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _08093974
	ldr r1, _08093928 @ =0x000020AC
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r4, _0809392C @ =0x00000121
	adds r0, r5, #0
	bl FUN_0808ba64
	adds r2, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r3, #0x10
	bl FUN_0808c164
	ldr r1, _08093930 @ =0x00003F9D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08093938
	movs r2, #0xd
	movs r3, #2
	ldr r6, _08093934 @ =0x000002ED
	b _0809393E
	.align 2, 0
_08093924: .4byte 0x000009EE
_08093928: .4byte 0x000020AC
_0809392C: .4byte 0x00000121
_08093930: .4byte 0x00003F9D
_08093934: .4byte 0x000002ED
_08093938:
	movs r2, #0
	movs r3, #1
	ldr r6, _0809397C @ =0x000002EE
_0809393E:
	ldr r0, _08093980 @ =0x00002524
	adds r4, r5, r0
	ldr r1, _08093984 @ =0x00003F9D
	adds r0, r5, r1
	ldrb r1, [r0]
	lsls r1, r1, #5
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r1, r0
	adds r1, r5, r1
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	bl MainSprite_SetAnim
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_0808ba0c
	ldr r0, _08093988 @ =0x0000010D
	bl PlaySound_082406e0
	ldr r1, _0809398C @ =FUN_08093990
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
_08093974:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809397C: .4byte 0x000002EE
_08093980: .4byte 0x00002524
_08093984: .4byte 0x00003F9D
_08093988: .4byte 0x0000010D
_0809398C: .4byte FUN_08093990
