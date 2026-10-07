	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r0, _080818A0 @ =0x0000CB05
	ldr r1, _080818A4 @ =0x0000DE23
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _08081846
	b _08081AA4
_08081846:
	adds r1, r6, #0
	adds r1, #0x68
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r6, #0
	adds r4, #0x68
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	adds r5, r6, #0
	adds r5, #0x88
	movs r3, #0x80
	lsls r3, r3, #8
	movs r0, #2
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	adds r0, r6, #0
	adds r0, #0x2c
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_Add
	movs r0, #0x64
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080818A8
	bl VM_GetValue
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r6, r2
	strb r0, [r1]
	b _080818B0
	.align 2, 0
_080818A0: .4byte 0x0000CB05
_080818A4: .4byte 0x0000DE23
_080818A8:
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r6, r3
	strb r1, [r0]
_080818B0:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r2, [r0]
	cmp r2, #4
	bls _080818D8
	movs r0, #8
	subs r0, r0, r2
	ldr r2, _080818D0 @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _080818D4 @ =0x000002E7
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	b _080818E6
	.align 2, 0
_080818D0: .4byte 0x000002E6
_080818D4: .4byte 0x000002E7
_080818D8:
	ldr r1, _08081918 @ =0x000002E6
	adds r0, r6, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _0808191C @ =0x000002E7
	adds r0, r6, r2
	strb r1, [r0]
_080818E6:
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r0, r6, r3
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08081918 @ =0x000002E6
	adds r0, r6, r2
	ldrb r2, [r0]
	str r1, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r3, _0808191C @ =0x000002E7
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08081920
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	b _0808192C
	.align 2, 0
_08081918: .4byte 0x000002E6
_0808191C: .4byte 0x000002E7
_08081920:
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_0808192C:
	str r1, [r0]
	add r0, sp, #0x10
	bl FUN_08084734
	adds r2, r6, #0
	movs r4, #0x8f
	lsls r4, r4, #3
	adds r5, r6, r4
	movs r0, #8
	adds r0, r0, r6
	mov ip, r0
	adds r7, r6, #0
	adds r7, #0x18
_08081946:
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	str r0, [r5]
	str r1, [r5, #4]
	cmp r2, ip
	beq _08081974
	cmp r2, ip
	bgt _0808195C
	cmp r2, r6
	beq _0808196A
	b _0808198E
_0808195C:
	adds r0, r6, #0
	adds r0, #0x10
	cmp r2, r0
	beq _0808197C
	cmp r2, r7
	beq _08081986
	b _0808198E
_0808196A:
	movs r1, #0x2c
	movs r4, #0xa0
	rsbs r4, r4, #0
	movs r3, #5
	b _08081994
_08081974:
	movs r1, #0x2c
	movs r4, #0xfc
	movs r3, #1
	b _08081994
_0808197C:
	movs r1, #0xa0
	rsbs r1, r1, #0
	movs r4, #0x2c
	movs r3, #3
	b _08081994
_08081986:
	movs r1, #0xfc
	movs r4, #0x2c
	movs r3, #7
	b _08081994
_0808198E:
	movs r1, #0
	movs r4, #0
	movs r3, #0
_08081994:
	ldrh r0, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	ldr r0, _080819D4 @ =0x0000047C
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, r0, r4
	strh r0, [r1]
	ldr r1, _080819D8 @ =0x0000047E
	adds r0, r2, r1
	strh r3, [r0]
	adds r2, #8
	adds r5, #8
	cmp r2, r7
	ble _08081946
	ldr r2, _080819DC @ =0x000004A6
	adds r0, r6, r2
	movs r1, #0
	strb r1, [r0]
	ldr r3, _080819E0 @ =0x00000466
	adds r0, r6, r3
	strb r1, [r0]
	movs r0, #0x72
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080819E8
	bl VM_GetValue
	ldr r4, _080819E4 @ =0x00000467
	adds r1, r6, r4
	b _080819EE
	.align 2, 0
_080819D4: .4byte 0x0000047C
_080819D8: .4byte 0x0000047E
_080819DC: .4byte 0x000004A6
_080819E0: .4byte 0x00000466
_080819E4: .4byte 0x00000467
_080819E8:
	ldr r5, _08081A10 @ =0x00000467
	adds r1, r6, r5
	movs r0, #0x32
_080819EE:
	strb r0, [r1]
	ldr r1, _08081A14 @ =0x00000469
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #0x62
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08081A18
	bl VM_GetValue
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r1, r6, r2
	b _08081A20
	.align 2, 0
_08081A10: .4byte 0x00000467
_08081A14: .4byte 0x00000469
_08081A18:
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r1, r6, r3
	movs r0, #3
_08081A20:
	strb r0, [r1]
	ldr r4, _08081A50 @ =0x0000046D
	adds r0, r6, r4
	movs r1, #0
	strb r1, [r0]
	ldr r5, _08081A54 @ =0x00000474
	adds r0, r6, r5
	strh r1, [r0]
	movs r0, #0x47
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08081A60
	bl VM_GetValue
	ldr r2, _08081A58 @ =0x0000046C
	adds r1, r6, r2
	strb r0, [r1]
	bl VM_GetValue
	ldr r3, _08081A5C @ =0x00000472
	adds r1, r6, r3
	b _08081A6E
	.align 2, 0
_08081A50: .4byte 0x0000046D
_08081A54: .4byte 0x00000474
_08081A58: .4byte 0x0000046C
_08081A5C: .4byte 0x00000472
_08081A60:
	ldr r4, _08081A8C @ =0x0000046C
	adds r1, r6, r4
	movs r0, #4
	strb r0, [r1]
	ldr r5, _08081A90 @ =0x00000472
	adds r1, r6, r5
	movs r0, #0xb4
_08081A6E:
	strh r0, [r1]
	ldr r1, _08081A94 @ =0x0000046B
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #0x73
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08081A9C
	bl VM_GetValue
	ldr r2, _08081A98 @ =0x0000046A
	adds r1, r6, r2
	b _08081AA2
	.align 2, 0
_08081A8C: .4byte 0x0000046C
_08081A90: .4byte 0x00000472
_08081A94: .4byte 0x0000046B
_08081A98: .4byte 0x0000046A
_08081A9C:
	ldr r3, _08081AAC @ =0x0000046A
	adds r1, r6, r3
	movs r0, #5
_08081AA2:
	strb r0, [r1]
_08081AA4:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08081AAC: .4byte 0x0000046A
