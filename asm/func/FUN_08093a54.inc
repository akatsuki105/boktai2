	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	ldr r1, _08093AB4 @ =0x00002524
	adds r0, r5, r1
	ldr r2, _08093AB8 @ =0x00003F9D
	adds r1, r5, r2
	ldrb r1, [r1]
	lsls r1, r1, #5
	movs r2, #0x90
	lsls r2, r2, #1
	adds r1, r1, r2
	adds r1, r5, r1
	bl MainSprite_AdvanceAnim
	movs r0, #0
	mov sb, r0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r6, r5, r1
	ldr r0, [r6]
	ldr r4, _08093ABC @ =0x0000036A
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x78
	bl Div
	adds r2, r0, #0
	cmp r2, #0
	bgt _08093A96
	movs r2, #1
_08093A96:
	ldr r1, [r6]
	movs r0, #0xda
	lsls r0, r0, #2
	mov r8, r0
	adds r3, r1, r0
	ldrh r0, [r3]
	adds r7, r0, r2
	adds r1, r1, r4
	ldrh r0, [r1]
	cmp r7, r0
	blt _08093AC0
	strh r0, [r3]
	movs r1, #1
	mov sb, r1
	b _08093ADC
	.align 2, 0
_08093AB4: .4byte 0x00002524
_08093AB8: .4byte 0x00003F9D
_08093ABC: .4byte 0x0000036A
_08093AC0:
	ldr r2, _08093B14 @ =0x000009EE
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #0
	bne _08093AD6
	ldr r0, _08093B18 @ =0x00000259
	bl PlaySound_082406e0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_08093AD6:
	ldr r0, [r6]
	add r0, r8
	strh r7, [r0]
_08093ADC:
	adds r0, r5, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl FUN_0808a768
	mov r0, sb
	cmp r0, #0
	beq _08093B08
	ldr r1, _08093B14 @ =0x000009EE
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08093AFE
	ldr r0, _08093B18 @ =0x00000259
	bl sound_08240740
_08093AFE:
	ldr r1, _08093B1C @ =FUN_08093b20
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
_08093B08:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08093B14: .4byte 0x000009EE
_08093B18: .4byte 0x00000259
_08093B1C: .4byte FUN_08093b20
