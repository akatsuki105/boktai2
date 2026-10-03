	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x62
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _080B1E5C
	bl VM_GetValue
	ldr r2, _080B1E54 @ =0x00001336
	adds r1, r5, r2
	strb r0, [r1]
	bl VM_GetValue
	ldr r4, _080B1E58 @ =0x030046A0
	ldr r1, [r4]
	movs r2, #0xae
	lsls r2, r2, #2
	adds r1, r1, r2
	str r0, [r1]
	bl VM_GetValue
	ldr r1, [r4]
	movs r2, #0xaf
	lsls r2, r2, #2
	adds r1, r1, r2
	str r0, [r1]
	b _080B1E7A
	.align 2, 0
_080B1E54: .4byte 0x00001336
_080B1E58: .4byte 0x030046A0
_080B1E5C:
	ldr r2, _080B1E9C @ =0x00001336
	adds r0, r5, r2
	strb r1, [r0]
	ldr r2, _080B1EA0 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0xae
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, _080B1EA4 @ =0x00001770
	str r1, [r0]
	ldr r0, [r2]
	movs r2, #0xaf
	lsls r2, r2, #2
	adds r0, r0, r2
	str r1, [r0]
_080B1E7A:
	ldr r0, _080B1EA0 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0xae
	lsls r2, r2, #2
	adds r1, r0, r2
	adds r2, #4
	adds r0, r0, r2
	ldr r0, [r0]
	asrs r0, r0, #2
	ldr r1, [r1]
	cmp r1, r0
	ble _080B1EAC
	ldr r0, _080B1EA8 @ =0x0000133F
	adds r1, r5, r0
	movs r0, #0
	b _080B1EB2
	.align 2, 0
_080B1E9C: .4byte 0x00001336
_080B1EA0: .4byte 0x030046A0
_080B1EA4: .4byte 0x00001770
_080B1EA8: .4byte 0x0000133F
_080B1EAC:
	ldr r2, _080B1ECC @ =0x0000133F
	adds r1, r5, r2
	movs r0, #1
_080B1EB2:
	strb r0, [r1]
	ldr r1, _080B1ED0 @ =0x00001336
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _080B1EC0
	b _080B2022
_080B1EC0:
	lsls r0, r0, #2
	ldr r1, _080B1ED4 @ =_080B1ED8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080B1ECC: .4byte 0x0000133F
_080B1ED0: .4byte 0x00001336
_080B1ED4: .4byte _080B1ED8
_080B1ED8: @ jump table
	.4byte _080B1EF0 @ case 0
	.4byte _080B1F28 @ case 1
	.4byte _080B1F5C @ case 2
	.4byte _080B1F94 @ case 3
	.4byte _080B1FC8 @ case 4
	.4byte _080B2000 @ case 5
_080B1EF0:
	movs r2, #0x9a
	lsls r2, r2, #5
	adds r1, r5, r2
	ldr r0, _080B1F14 @ =0x0000023F
	strh r0, [r1]
	ldr r0, _080B1F18 @ =0x00001342
	adds r1, r5, r0
	ldr r0, _080B1F1C @ =0x00000245
	strh r0, [r1]
	adds r2, #4
	adds r1, r5, r2
	adds r0, #0xd
	strh r0, [r1]
	ldr r0, _080B1F20 @ =0x00001346
	adds r1, r5, r0
	ldr r0, _080B1F24 @ =0x0000024B
	b _080B2020
	.align 2, 0
_080B1F14: .4byte 0x0000023F
_080B1F18: .4byte 0x00001342
_080B1F1C: .4byte 0x00000245
_080B1F20: .4byte 0x00001346
_080B1F24: .4byte 0x0000024B
_080B1F28:
	movs r2, #0x9a
	lsls r2, r2, #5
	adds r1, r5, r2
	movs r0, #0x90
	lsls r0, r0, #2
	strh r0, [r1]
	ldr r0, _080B1F50 @ =0x00001342
	adds r1, r5, r0
	ldr r0, _080B1F54 @ =0x00000246
	strh r0, [r1]
	adds r2, #4
	adds r1, r5, r2
	adds r0, #0xd
	strh r0, [r1]
	ldr r0, _080B1F58 @ =0x00001346
	adds r1, r5, r0
	movs r0, #0x93
	lsls r0, r0, #2
	b _080B2020
	.align 2, 0
_080B1F50: .4byte 0x00001342
_080B1F54: .4byte 0x00000246
_080B1F58: .4byte 0x00001346
_080B1F5C:
	movs r2, #0x9a
	lsls r2, r2, #5
	adds r1, r5, r2
	ldr r0, _080B1F80 @ =0x00000241
	strh r0, [r1]
	ldr r0, _080B1F84 @ =0x00001342
	adds r1, r5, r0
	ldr r0, _080B1F88 @ =0x00000247
	strh r0, [r1]
	adds r2, #4
	adds r1, r5, r2
	adds r0, #0xd
	strh r0, [r1]
	ldr r0, _080B1F8C @ =0x00001346
	adds r1, r5, r0
	ldr r0, _080B1F90 @ =0x0000024D
	b _080B2020
	.align 2, 0
_080B1F80: .4byte 0x00000241
_080B1F84: .4byte 0x00001342
_080B1F88: .4byte 0x00000247
_080B1F8C: .4byte 0x00001346
_080B1F90: .4byte 0x0000024D
_080B1F94:
	movs r2, #0x9a
	lsls r2, r2, #5
	adds r1, r5, r2
	ldr r0, _080B1FB8 @ =0x00000242
	strh r0, [r1]
	ldr r0, _080B1FBC @ =0x00001342
	adds r1, r5, r0
	movs r0, #0x92
	lsls r0, r0, #2
	strh r0, [r1]
	adds r2, #4
	adds r1, r5, r2
	adds r0, #0xd
	strh r0, [r1]
	ldr r0, _080B1FC0 @ =0x00001346
	adds r1, r5, r0
	ldr r0, _080B1FC4 @ =0x0000024E
	b _080B2020
	.align 2, 0
_080B1FB8: .4byte 0x00000242
_080B1FBC: .4byte 0x00001342
_080B1FC0: .4byte 0x00001346
_080B1FC4: .4byte 0x0000024E
_080B1FC8:
	movs r2, #0x9a
	lsls r2, r2, #5
	adds r1, r5, r2
	ldr r0, _080B1FEC @ =0x00000243
	strh r0, [r1]
	ldr r0, _080B1FF0 @ =0x00001342
	adds r1, r5, r0
	ldr r0, _080B1FF4 @ =0x00000249
	strh r0, [r1]
	adds r2, #4
	adds r1, r5, r2
	adds r0, #0xd
	strh r0, [r1]
	ldr r0, _080B1FF8 @ =0x00001346
	adds r1, r5, r0
	ldr r0, _080B1FFC @ =0x0000024F
	b _080B2020
	.align 2, 0
_080B1FEC: .4byte 0x00000243
_080B1FF0: .4byte 0x00001342
_080B1FF4: .4byte 0x00000249
_080B1FF8: .4byte 0x00001346
_080B1FFC: .4byte 0x0000024F
_080B2000:
	movs r1, #0x9a
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r1, #0x91
	lsls r1, r1, #2
	strh r1, [r0]
	ldr r2, _080B2038 @ =0x00001342
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, _080B203C @ =0x00001344
	adds r1, r5, r0
	ldr r0, _080B2040 @ =0x00000257
	strh r0, [r1]
	adds r2, #4
	adds r1, r5, r2
	subs r0, #7
_080B2020:
	strh r0, [r1]
_080B2022:
	movs r0, #0x54
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080B2048
	bl VM_GetValue
	ldr r2, _080B2044 @ =0x0000134E
	adds r1, r5, r2
	b _080B204E
	.align 2, 0
_080B2038: .4byte 0x00001342
_080B203C: .4byte 0x00001344
_080B2040: .4byte 0x00000257
_080B2044: .4byte 0x0000134E
_080B2048:
	ldr r0, _080B205C @ =0x0000134E
	adds r1, r5, r0
	movs r0, #0xa
_080B204E:
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080af0f8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B205C: .4byte 0x0000134E
