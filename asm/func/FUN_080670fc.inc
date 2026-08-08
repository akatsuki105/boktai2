	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	mov r8, r1
	adds r0, #0x9c
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _08067116
	b _080672A2
_08067116:
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	beq _08067122
	b _080672A2
_08067122:
	ldr r1, _08067164 @ =0x00000446
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r6, #0
	adds r7, r0, #0
	cmp r1, #0
	beq _0806713C
	ldr r2, _08067168 @ =0x00000442
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806713C
	movs r6, #1
_0806713C:
	cmp r6, #0
	beq _08067142
	b _080672A2
_08067142:
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	bl FUN_0809f658
	cmp r0, #0
	beq _0806717A
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _08067170
	str r4, [sp]
	str r6, [sp, #4]
	ldr r0, _0806716C @ =0x00000163
	b _080671C2
	.align 2, 0
_08067164: .4byte 0x00000446
_08067168: .4byte 0x00000442
_0806716C: .4byte 0x00000163
_08067170:
	str r4, [sp]
	str r6, [sp, #4]
	movs r0, #0xb1
	lsls r0, r0, #1
	b _080671C2
_0806717A:
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	bl FUN_08065a98
	cmp r0, #0
	beq _080671D8
	ldrh r0, [r7]
	movs r1, #0
	cmp r0, #0
	beq _0806719E
	ldr r2, _080671B8 @ =0x00000442
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _0806719E
	movs r1, #1
_0806719E:
	cmp r1, #0
	bne _080671D8
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _080671BC
	str r4, [sp]
	str r1, [sp, #4]
	movs r0, #0xca
	lsls r0, r0, #1
	b _080671C2
	.align 2, 0
_080671B8: .4byte 0x00000442
_080671BC:
	str r4, [sp]
	str r1, [sp, #4]
	ldr r0, _080671D4 @ =0x00000193
_080671C2:
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	movs r3, #1
	bl FUN_08066e9c
	b _080672A2
	.align 2, 0
_080671D4: .4byte 0x00000193
_080671D8:
	mov r0, r8
	cmp r0, #0
	bne _08067266
	ldrh r0, [r7]
	movs r1, #0
	cmp r0, #0
	beq _080671F2
	ldr r2, _08067208 @ =0x00000442
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _080671F2
	movs r1, #1
_080671F2:
	cmp r1, #0
	beq _08067214
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806720C
	movs r0, #0xc8
	bl PlaySound_082406e0
	b _08067266
	.align 2, 0
_08067208: .4byte 0x00000442
_0806720C:
	movs r0, #0xc7
	bl PlaySound_082406e0
	b _08067266
_08067214:
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0806722A
	ldr r2, _0806723C @ =0x000001C7
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08067248
_0806722A:
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _08067240
	movs r0, #0xca
	bl PlaySound_082406e0
	b _08067266
	.align 2, 0
_0806723C: .4byte 0x000001C7
_08067240:
	movs r0, #0xc9
	bl PlaySound_082406e0
	b _08067266
_08067248:
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _08067260
	ldr r0, _0806725C @ =0x0000028E
	bl PlaySound_082406e0
	b _08067266
	.align 2, 0
_0806725C: .4byte 0x0000028E
_08067260:
	ldr r0, _0806727C @ =0x0000028D
	bl PlaySound_082406e0
_08067266:
	movs r1, #1
	ldr r0, _08067280 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _08067284 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08067288
	movs r0, #1
	b _0806728A
	.align 2, 0
_0806727C: .4byte 0x0000028D
_08067280: .4byte 0x030046A0
_08067284: .4byte 0x00000934
_08067288:
	movs r0, #0
_0806728A:
	cmp r0, #0
	beq _080672A2
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	movs r3, #2
	bl FUN_08066e9c
_080672A2:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
