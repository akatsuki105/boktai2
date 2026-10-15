	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r1, #0
	cmp r0, #0
	bne _081E3968
	b _081E3CAC
_081E3968:
	adds r4, r0, #0
	ldrh r0, [r6]
	adds r1, r0, #0
	cmp r1, #0
	bne _081E3976
	movs r0, #1
	b _081E3978
_081E3976:
	movs r0, #0
_081E3978:
	cmp r0, #0
	beq _081E398C
	ldr r1, [r6, #4]
	ldr r2, _081E3988 @ =0x00000BB6
	adds r0, r4, r2
	strh r1, [r0]
	movs r2, #4
	b _081E3C9E
	.align 2, 0
_081E3988: .4byte 0x00000BB6
_081E398C:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _081E3998
	movs r0, #1
	b _081E399A
_081E3998:
	movs r0, #0
_081E399A:
	cmp r0, #0
	beq _081E39E8
	adds r1, r6, #4
	movs r3, #0
	ldrb r0, [r6, #4]
	ldr r5, _081E39E0 @ =0x00001610
	adds r5, r5, r4
	mov sb, r5
	cmp r0, #0
	beq _081E39C8
	ldr r7, _081E39E4 @ =0x00000BB8
	adds r5, r4, r7
	adds r2, r1, #0
_081E39B4:
	adds r0, r5, r3
	ldrb r1, [r2]
	strb r1, [r0]
	adds r2, #1
	adds r3, #1
	ldrb r0, [r2]
	cmp r0, #0
	beq _081E39C8
	cmp r3, #0xb
	ble _081E39B4
_081E39C8:
	ldr r1, _081E39E4 @ =0x00000BB8
	adds r0, r4, r1
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0]
	movs r1, #2
	mov r2, sb
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	b _081E3CA8
	.align 2, 0
_081E39E0: .4byte 0x00001610
_081E39E4: .4byte 0x00000BB8
_081E39E8:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bne _081E39F4
	movs r0, #1
	b _081E39F6
_081E39F4:
	movs r0, #0
_081E39F6:
	cmp r0, #0
	beq _081E3A20
	ldr r1, [r6, #4]
	ldr r3, _081E3A14 @ =0x00000BB4
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, [r6, #8]
	ldr r5, _081E3A18 @ =0x00000BB5
	adds r0, r4, r5
	strb r1, [r0]
	movs r2, #8
	ldr r7, _081E3A1C @ =0x00001610
	adds r1, r4, r7
	b _081E3CA2
	.align 2, 0
_081E3A14: .4byte 0x00000BB4
_081E3A18: .4byte 0x00000BB5
_081E3A1C: .4byte 0x00001610
_081E3A20:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xa
	bne _081E3A2C
	movs r0, #1
	b _081E3A2E
_081E3A2C:
	movs r0, #0
_081E3A2E:
	cmp r0, #0
	beq _081E3A60
	ldr r0, [r6, #4]
	movs r2, #0xb1
	lsls r2, r2, #5
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0x80
	ldr r5, _081E3A5C @ =0x00001610
	adds r3, r4, r5
	ldr r2, [r3]
	orrs r2, r0
	str r2, [r3]
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, #4
	beq _081E3A52
	b _081E3CA8
_081E3A52:
	movs r0, #0x80
	lsls r0, r0, #0xd
	orrs r2, r0
	str r2, [r3]
	b _081E3CA8
	.align 2, 0
_081E3A5C: .4byte 0x00001610
_081E3A60:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bne _081E3A6C
	movs r0, #1
	b _081E3A6E
_081E3A6C:
	movs r0, #0
_081E3A6E:
	cmp r0, #0
	beq _081E3B40
	ldr r1, [r6, #4]
	ldr r2, _081E3A84 @ =0x000015BC
	adds r0, r4, r2
	strb r1, [r0]
	cmp r1, #0
	blt _081E3A88
	asrs r2, r1, #8
	b _081E3A8E
	.align 2, 0
_081E3A84: .4byte 0x000015BC
_081E3A88:
	rsbs r0, r1, #0
	asrs r0, r0, #8
	rsbs r2, r0, #0
_081E3A8E:
	ldr r3, _081E3A9C @ =0x000015BD
	adds r0, r4, r3
	strb r2, [r0]
	cmp r1, #0
	blt _081E3AA0
	asrs r2, r1, #0x10
	b _081E3AA6
	.align 2, 0
_081E3A9C: .4byte 0x000015BD
_081E3AA0:
	rsbs r0, r1, #0
	asrs r0, r0, #0x10
	rsbs r2, r0, #0
_081E3AA6:
	ldr r5, _081E3AB4 @ =0x000015BE
	adds r0, r4, r5
	strb r2, [r0]
	cmp r1, #0
	blt _081E3AB8
	asrs r1, r1, #0x18
	b _081E3ABE
	.align 2, 0
_081E3AB4: .4byte 0x000015BE
_081E3AB8:
	rsbs r0, r1, #0
	asrs r0, r0, #0x18
	rsbs r1, r0, #0
_081E3ABE:
	ldr r7, _081E3AD8 @ =0x000015BF
	adds r0, r4, r7
	strb r1, [r0]
	ldr r1, [r6, #8]
	movs r2, #0xae
	lsls r2, r2, #5
	adds r0, r4, r2
	strb r1, [r0]
	cmp r1, #0
	blt _081E3ADC
	asrs r2, r1, #8
	b _081E3AE2
	.align 2, 0
_081E3AD8: .4byte 0x000015BF
_081E3ADC:
	rsbs r0, r1, #0
	asrs r0, r0, #8
	rsbs r2, r0, #0
_081E3AE2:
	ldr r3, _081E3AF0 @ =0x000015C1
	adds r0, r4, r3
	strb r2, [r0]
	cmp r1, #0
	blt _081E3AF4
	asrs r1, r1, #0x10
	b _081E3AFA
	.align 2, 0
_081E3AF0: .4byte 0x000015C1
_081E3AF4:
	rsbs r0, r1, #0
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
_081E3AFA:
	ldr r5, _081E3B10 @ =0x000015C2
	adds r0, r4, r5
	strh r1, [r0]
	ldr r1, [r6, #0xc]
	ldr r7, _081E3B14 @ =0x000015C4
	adds r0, r4, r7
	strh r1, [r0]
	cmp r1, #0
	blt _081E3B18
	asrs r1, r1, #0x10
	b _081E3B1E
	.align 2, 0
_081E3B10: .4byte 0x000015C2
_081E3B14: .4byte 0x000015C4
_081E3B18:
	rsbs r0, r1, #0
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
_081E3B1E:
	ldr r2, _081E3B38 @ =0x000015C6
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r1, [r6, #2]
	movs r3, #0xaf
	lsls r3, r3, #5
	adds r0, r4, r3
	strh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r5, _081E3B3C @ =0x00001610
	adds r1, r4, r5
	b _081E3CA2
	.align 2, 0
_081E3B38: .4byte 0x000015C6
_081E3B3C: .4byte 0x00001610
_081E3B40:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bne _081E3B4C
	movs r0, #1
	b _081E3B4E
_081E3B4C:
	movs r0, #0
_081E3B4E:
	cmp r0, #0
	beq _081E3B7C
	movs r7, #0xaf
	lsls r7, r7, #5
	adds r0, r4, r7
	ldrh r0, [r0]
	ldrh r1, [r6, #2]
	cmp r0, r1
	bne _081E3B9C
	adds r5, r6, #4
	movs r2, #0
	ldr r7, _081E3B78 @ =0x000015C8
	adds r3, r4, r7
_081E3B68:
	adds r0, r3, r2
	adds r1, r5, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #0xb
	ble _081E3B68
	b _081E3CA8
	.align 2, 0
_081E3B78: .4byte 0x000015C8
_081E3B7C:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne _081E3B88
	movs r0, #1
	b _081E3B8A
_081E3B88:
	movs r0, #0
_081E3B8A:
	cmp r0, #0
	beq _081E3C60
	movs r1, #0xaf
	lsls r1, r1, #5
	adds r0, r4, r1
	ldrh r0, [r0]
	ldrh r2, [r6, #2]
	cmp r0, r2
	beq _081E3BA2
_081E3B9C:
	bl LinkShopManager_Abort
	b _081E3CAC
_081E3BA2:
	ldr r3, _081E3C3C @ =0x00001610
	adds r3, r3, r4
	mov sb, r3
	adds r3, r4, #0
	adds r2, r6, #4
	movs r5, #2
_081E3BAE:
	ldrb r1, [r2]
	ldr r7, _081E3C40 @ =0x000015D4
	adds r0, r3, r7
	strb r1, [r0]
	adds r2, #1
	ldrb r1, [r2]
	adds r7, #1
	adds r0, r3, r7
	strb r1, [r0]
	adds r2, #1
	ldrb r1, [r2]
	adds r7, #1
	adds r0, r3, r7
	strb r1, [r0]
	adds r2, #1
	ldrb r1, [r2]
	adds r7, #1
	adds r0, r3, r7
	strb r1, [r0]
	adds r2, #1
	adds r3, #4
	subs r5, #1
	cmp r5, #0
	bge _081E3BAE
	ldr r0, _081E3C44 @ =0x00000E28
	adds r0, r0, r4
	mov ip, r0
	ldr r1, _081E3C48 @ =0x000015BC
	adds r1, r1, r4
	mov r8, r1
	mov r1, ip
	mov r0, r8
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldm r0!, {r2, r5, r7}
	stm r1!, {r2, r5, r7}
	ldr r3, _081E3C4C @ =0x00000E04
	adds r0, r4, r3
	mov r2, r8
	ldm r2!, {r1, r5, r7}
	stm r0!, {r1, r5, r7}
	ldm r2!, {r3, r5, r7}
	stm r0!, {r3, r5, r7}
	ldm r2!, {r1, r3, r5}
	stm r0!, {r1, r3, r5}
	ldr r7, _081E3C50 @ =0x000014AC
	adds r0, r4, r7
	ldr r2, _081E3C54 @ =0x0000156C
	adds r1, r4, r2
	mov r3, ip
	ldrb r2, [r3]
	bl MainSprite_LoadPose
	ldr r5, _081E3C58 @ =0x000014B4
	adds r2, r4, r5
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r7, sb
	ldr r0, [r7]
	orrs r0, r1
	ldr r1, _081E3C5C @ =0xFFFFF7FF
	ands r0, r1
	str r0, [r7]
	b _081E3CA8
	.align 2, 0
_081E3C3C: .4byte 0x00001610
_081E3C40: .4byte 0x000015D4
_081E3C44: .4byte 0x00000E28
_081E3C48: .4byte 0x000015BC
_081E3C4C: .4byte 0x00000E04
_081E3C50: .4byte 0x000014AC
_081E3C54: .4byte 0x0000156C
_081E3C58: .4byte 0x000014B4
_081E3C5C: .4byte 0xFFFFF7FF
_081E3C60:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bne _081E3C6C
	movs r0, #1
	b _081E3C6E
_081E3C6C:
	movs r0, #0
_081E3C6E:
	cmp r0, #0
	beq _081E3C80
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r0, _081E3C7C @ =0x00001610
	adds r1, r4, r0
	b _081E3CA2
	.align 2, 0
_081E3C7C: .4byte 0x00001610
_081E3C80:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xc
	bne _081E3C8C
	movs r0, #1
	b _081E3C8E
_081E3C8C:
	movs r0, #0
_081E3C8E:
	cmp r0, #0
	beq _081E3CA8
	ldr r1, [r6, #4]
	ldr r2, _081E3CB8 @ =0x000015E2
	adds r0, r4, r2
	strh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #5
_081E3C9E:
	ldr r3, _081E3CBC @ =0x00001610
	adds r1, r4, r3
_081E3CA2:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081E3CA8:
	movs r0, #0
	strh r0, [r6]
_081E3CAC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E3CB8: .4byte 0x000015E2
_081E3CBC: .4byte 0x00001610
