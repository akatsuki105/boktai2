	push {r4, r5, r6, lr}
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	bne _080EF164
	b _080EF4DA
_080EF164:
	bl FUN_080edda0
	adds r4, r0, #0
	cmp r4, #0
	bne _080EF170
	b _080EF4DA
_080EF170:
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080EF1D6
	bl VM_GetPC
	cmp r0, #0
	beq _080EF18A
	bl Script_GetValue
	adds r3, r0, #0
	b _080EF18E
_080EF18A:
	movs r3, #1
	rsbs r3, r3, #0
_080EF18E:
	cmp r3, #0
	blt _080EF1B8
	movs r1, #0xf0
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r3, [r0]
	movs r2, #0xf1
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r3, [r1]
	movs r3, #0xf6
	lsls r3, r3, #1
	adds r2, r4, r3
	ldrh r0, [r0]
	adds r1, r0, #0
	muls r1, r0, r1
	str r1, [r2]
	movs r2, #0xf8
	lsls r2, r2, #1
	adds r0, r4, r2
	str r1, [r0]
_080EF1B8:
	bl VM_GetPC
	cmp r0, #0
	beq _080EF1C8
	bl Script_GetValue
	adds r3, r0, #0
	b _080EF1CC
_080EF1C8:
	movs r3, #1
	rsbs r3, r3, #0
_080EF1CC:
	cmp r3, #0
	blt _080EF1D6
	ldr r1, _080EF1F4 @ =0x000001FD
	adds r0, r4, r1
	strb r3, [r0]
_080EF1D6:
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080EF27A
	movs r5, #0
	movs r6, #0
_080EF1E4:
	bl VM_GetPC
	cmp r0, #0
	beq _080EF1F8
	bl Script_GetValue
	adds r3, r0, #0
	b _080EF1FC
	.align 2, 0
_080EF1F4: .4byte 0x000001FD
_080EF1F8:
	movs r3, #1
	rsbs r3, r3, #0
_080EF1FC:
	cmp r3, #0
	blt _080EF20A
	movs r2, #0x89
	lsls r2, r2, #2
	adds r0, r4, r2
	adds r0, r0, r6
	strh r3, [r0]
_080EF20A:
	bl VM_GetPC
	cmp r0, #0
	beq _080EF21A
	bl Script_GetValue
	adds r3, r0, #0
	b _080EF21E
_080EF21A:
	movs r3, #1
	rsbs r3, r3, #0
_080EF21E:
	cmp r3, #0
	blt _080EF22C
	movs r1, #0x8b
	lsls r1, r1, #2
	adds r0, r4, r1
	adds r0, r0, r6
	strh r3, [r0]
_080EF22C:
	bl VM_GetPC
	cmp r0, #0
	beq _080EF23C
	bl Script_GetValue
	adds r3, r0, #0
	b _080EF240
_080EF23C:
	movs r3, #1
	rsbs r3, r3, #0
_080EF240:
	cmp r3, #0
	blt _080EF250
	lsls r1, r5, #2
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r0, r4, r2
	adds r0, r0, r1
	str r3, [r0]
_080EF250:
	bl VM_GetPC
	cmp r0, #0
	beq _080EF260
	bl Script_GetValue
	adds r3, r0, #0
	b _080EF264
_080EF260:
	movs r3, #1
	rsbs r3, r3, #0
_080EF264:
	cmp r3, #0
	blt _080EF272
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r0, r4, r1
	adds r0, r0, r6
	strh r3, [r0]
_080EF272:
	adds r6, #2
	adds r5, #1
	cmp r5, #3
	ble _080EF1E4
_080EF27A:
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080EF360
	bl VM_GetPC
	cmp r0, #0
	beq _080EF294
	bl Script_GetValue
	adds r3, r0, #0
	b _080EF298
_080EF294:
	movs r3, #1
	rsbs r3, r3, #0
_080EF298:
	cmp r3, #0
	blt _080EF2B8
	movs r0, #0x95
	lsls r0, r0, #2
	adds r2, r4, r0
	strh r3, [r2]
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x12
	ldr r3, _080EF2C8 @ =0x00000546
	adds r1, r4, r3
	strh r0, [r1]
	ldrh r1, [r2]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r1, [r0]
_080EF2B8:
	bl VM_GetPC
	cmp r0, #0
	beq _080EF2CC
	bl Script_GetValue
	adds r3, r0, #0
	b _080EF2D0
	.align 2, 0
_080EF2C8: .4byte 0x00000546
_080EF2CC:
	movs r3, #1
	rsbs r3, r3, #0
_080EF2D0:
	cmp r3, #0
	blt _080EF2DC
	movs r1, #0xc3
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r3, [r0]
_080EF2DC:
	bl VM_GetPC
	cmp r0, #0
	beq _080EF2EC
	bl Script_GetValue
	adds r3, r0, #0
	b _080EF2F0
_080EF2EC:
	movs r3, #1
	rsbs r3, r3, #0
_080EF2F0:
	cmp r3, #0
	blt _080EF2FA
	ldr r2, _080EF30C @ =0x00000187
	adds r0, r4, r2
	strb r3, [r0]
_080EF2FA:
	bl VM_GetPC
	cmp r0, #0
	beq _080EF310
	bl Script_GetValue
	adds r3, r0, #0
	b _080EF314
	.align 2, 0
_080EF30C: .4byte 0x00000187
_080EF310:
	movs r3, #1
	rsbs r3, r3, #0
_080EF314:
	cmp r3, #0
	blt _080EF320
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r0, r4, r1
	strb r3, [r0]
_080EF320:
	bl VM_GetPC
	cmp r0, #0
	beq _080EF330
	bl Script_GetValue
	adds r3, r0, #0
	b _080EF334
_080EF330:
	movs r3, #1
	rsbs r3, r3, #0
_080EF334:
	cmp r3, #0
	blt _080EF340
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r3, [r0]
_080EF340:
	bl VM_GetPC
	cmp r0, #0
	beq _080EF350
	bl Script_GetValue
	adds r3, r0, #0
	b _080EF354
_080EF350:
	movs r3, #1
	rsbs r3, r3, #0
_080EF354:
	cmp r3, #0
	blt _080EF360
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r3, [r0]
_080EF360:
	movs r0, #0x6c
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080EF3CA
	bl VM_GetPC
	cmp r0, #0
	beq _080EF37A
	bl Script_GetValue
	adds r3, r0, #0
	b _080EF37E
_080EF37A:
	movs r3, #1
	rsbs r3, r3, #0
_080EF37E:
	cmp r3, #0
	blt _080EF38A
	movs r2, #0xc7
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r3, [r0]
_080EF38A:
	bl VM_GetPC
	cmp r0, #0
	beq _080EF39A
	bl Script_GetValue
	adds r3, r0, #0
	b _080EF39E
_080EF39A:
	movs r3, #1
	rsbs r3, r3, #0
_080EF39E:
	cmp r3, #0
	blt _080EF3AA
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r3, [r0]
_080EF3AA:
	bl VM_GetPC
	cmp r0, #0
	beq _080EF3BA
	bl Script_GetValue
	adds r3, r0, #0
	b _080EF3BE
_080EF3BA:
	movs r3, #1
	rsbs r3, r3, #0
_080EF3BE:
	cmp r3, #0
	blt _080EF3CA
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r3, [r0]
_080EF3CA:
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080EF424
	bl VM_GetPC
	cmp r0, #0
	beq _080EF3E4
	bl Script_GetValue
	adds r3, r0, #0
	b _080EF3E8
_080EF3E4:
	movs r3, #1
	rsbs r3, r3, #0
_080EF3E8:
	cmp r3, #0
	blt _080EF404
	movs r1, #0x80
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r3, [r0]
	movs r2, #0xfa
	lsls r2, r2, #1
	adds r1, r4, r2
	ldrh r0, [r0]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	str r0, [r1]
_080EF404:
	bl VM_GetPC
	cmp r0, #0
	beq _080EF414
	bl Script_GetValue
	adds r3, r0, #0
	b _080EF418
_080EF414:
	movs r3, #1
	rsbs r3, r3, #0
_080EF418:
	cmp r3, #0
	blt _080EF424
	movs r1, #0xff
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r3, [r0]
_080EF424:
	movs r0, #0x52
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080EF43E
	movs r0, #0x52
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0xca
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
_080EF43E:
	movs r0, #0x46
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080EF458
	movs r0, #0x46
	movs r1, #0
	bl VM_GetKeywordValue
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r1, r4, r3
	strh r0, [r1]
_080EF458:
	movs r0, #0x49
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080EF472
	movs r0, #0x49
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
_080EF472:
	movs r0, #0x44
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080EF48C
	movs r0, #0x44
	movs r1, #0
	bl VM_GetKeywordValue
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r1, r4, r3
	strh r0, [r1]
_080EF48C:
	movs r0, #0x47
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080EF4C2
	movs r5, #0
_080EF498:
	bl VM_GetPC
	cmp r0, #0
	beq _080EF4A8
	bl Script_GetValue
	adds r3, r0, #0
	b _080EF4AC
_080EF4A8:
	movs r3, #1
	rsbs r3, r3, #0
_080EF4AC:
	cmp r3, #0
	blt _080EF4BC
	lsls r1, r5, #2
	movs r2, #0xce
	lsls r2, r2, #1
	adds r0, r4, r2
	adds r0, r0, r1
	str r3, [r0]
_080EF4BC:
	adds r5, #1
	cmp r5, #4
	ble _080EF498
_080EF4C2:
	movs r0, #0x4b
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080EF4DA
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetKeywordValue
	ldr r3, _080EF4E0 @ =0x0000025A
	adds r1, r4, r3
	strh r0, [r1]
_080EF4DA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080EF4E0: .4byte 0x0000025A
