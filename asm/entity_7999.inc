	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081d9da4
FUN_081d9da4: @ 0x081D9DA4
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _081D9DC4 @ =0x03002C68
	ldr r0, [r0]
	mov ip, r0
	cmp r0, #0
	beq _081D9DBC
	movs r4, #0xae
	lsls r4, r4, #1
	add r4, ip
	cmp r4, #0
	bne _081D9DC8
_081D9DBC:
	movs r0, #1
	rsbs r0, r0, #0
	b _081D9E48
	.align 2, 0
_081D9DC4: .4byte 0x03002C68
_081D9DC8:
	ldr r1, _081D9DF0 @ =0x00000286
	adds r0, r3, r1
	ldrb r0, [r0]
	subs r1, #0xea
	add r1, ip
	strb r0, [r1]
	ldr r2, _081D9DF4 @ =0x00000287
	adds r0, r3, r2
	ldrb r0, [r0]
	subs r2, #0xea
	add r2, ip
	strb r0, [r2]
	ldrb r0, [r1]
	cmp r0, #1
	beq _081D9E14
	cmp r0, #1
	bgt _081D9DF8
	cmp r0, #0
	beq _081D9DFE
	b _081D9E38
	.align 2, 0
_081D9DF0: .4byte 0x00000286
_081D9DF4: .4byte 0x00000287
_081D9DF8:
	cmp r0, #2
	beq _081D9E1C
	b _081D9E38
_081D9DFE:
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r1, r3, r2
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r2, #0xf2
	b _081D9E2E
_081D9E14:
	ldr r1, _081D9E18 @ =0x085AE160
	b _081D9E1E
	.align 2, 0
_081D9E18: .4byte 0x085AE160
_081D9E1C:
	ldr r1, _081D9E34 @ =0x085AE168
_081D9E1E:
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r0, r3, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	subs r2, #0xea
_081D9E2E:
	add r2, ip
	strb r0, [r2]
	b _081D9E46
	.align 2, 0
_081D9E34: .4byte 0x085AE168
_081D9E38:
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	adds r0, #0x42
	strb r1, [r0]
_081D9E46:
	movs r0, #0
_081D9E48:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d9e50
FUN_081d9e50: @ 0x081D9E50
	push {r4, r5, lr}
	adds r1, r0, #0
	ldr r2, _081D9E68 @ =0x00000286
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _081D9E9C
	cmp r0, #1
	bgt _081D9E6C
	cmp r0, #0
	beq _081D9E72
	b _081D9EE4
	.align 2, 0
_081D9E68: .4byte 0x00000286
_081D9E6C:
	cmp r0, #2
	beq _081D9EBC
	b _081D9EE4
_081D9E72:
	movs r2, #0
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r2, r0
	bge _081D9EEE
	subs r3, #4
	adds r5, r1, r3
	adds r3, #8
	adds r4, r1, r3
	ldrb r1, [r5]
	adds r3, r0, #0
_081D9E8C:
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r1, r0
	beq _081D9EDC
	adds r2, #1
	cmp r2, r3
	blt _081D9E8C
	b _081D9EEE
_081D9E9C:
	movs r2, #0
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r4, r1, r0
	ldrb r1, [r4]
	ldr r3, _081D9EB8 @ =0x085AE160
_081D9EA8:
	ldr r0, [r3]
	cmp r1, r0
	beq _081D9EE0
	adds r3, #4
	adds r2, #1
	cmp r2, #1
	ble _081D9EA8
	b _081D9EEE
	.align 2, 0
_081D9EB8: .4byte 0x085AE160
_081D9EBC:
	movs r2, #0
	movs r3, #0xa2
	lsls r3, r3, #2
	adds r4, r1, r3
	ldrb r1, [r4]
	ldr r3, _081D9ED8 @ =0x085AE168
_081D9EC8:
	ldr r0, [r3]
	cmp r1, r0
	beq _081D9EE0
	adds r3, #4
	adds r2, #1
	cmp r2, #0
	ble _081D9EC8
	b _081D9EEE
	.align 2, 0
_081D9ED8: .4byte 0x085AE168
_081D9EDC:
	strb r2, [r5]
	b _081D9EEE
_081D9EE0:
	strb r2, [r4]
	b _081D9EEE
_081D9EE4:
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r0, #0
	strb r0, [r1]
_081D9EEE:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d9ef4
FUN_081d9ef4: @ 0x081D9EF4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081da370
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	bl FUN_08049e5c
	adds r0, r4, #0
	bl FUN_081da5d0
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081D9F36
	movs r1, #0
	bl Script_ExecById
	adds r0, r4, #0
	bl KillEntity
_081D9F36:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d9f3c
FUN_081d9f3c: @ 0x081D9F3C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08049fa8
	adds r0, r4, #0
	bl FUN_081da370
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r4, #0
	bl FUN_081da5d0
	bl FUN_081df974
	ldr r0, _081D9F88 @ =0x000002A2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081D9F82
	movs r1, #0
	bl Script_ExecById
	adds r0, r4, #0
	bl KillEntity
_081D9F82:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081D9F88: .4byte 0x000002A2

	thumb_func_start FUN_081d9f8c
FUN_081d9f8c: @ 0x081D9F8C
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081D9FF0 @ =0x0000C091
	ldr r1, _081D9FF4 @ =0x0000CD91
	bl GetFile
	adds r2, r0, #0
	str r2, [r5, #0x18]
	movs r0, #5
	str r0, [sp, #0xc]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _081D9FF8 @ =0x000092B3
	ldr r1, _081D9FFC @ =0x000026BB
	bl GetFile
	adds r0, #0x14
	str r0, [r5, #0x1c]
	ldr r1, _081DA000 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	ldr r0, _081DA004 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DA008
	adds r0, #0x56
	ldrb r0, [r0]
	cmp r0, #1
	bne _081DA008
	movs r0, #1
	b _081DA00A
	.align 2, 0
_081D9FF0: .4byte 0x0000C091
_081D9FF4: .4byte 0x0000CD91
_081D9FF8: .4byte 0x000092B3
_081D9FFC: .4byte 0x000026BB
_081DA000: .4byte 0x03004250
_081DA004: .4byte 0x03002C68
_081DA008:
	movs r0, #0
_081DA00A:
	cmp r0, #0
	bne _081DA02E
	movs r4, #0
	movs r5, #3
_081DA012:
	adds r0, r4, #0
	adds r0, #0x19
	adds r1, r4, #0
	adds r1, #0x16
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl FUN_080e1238
	adds r4, #1
	cmp r4, #4
	ble _081DA012
_081DA02E:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081da038
FUN_081da038: @ 0x081DA038
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r5, #0
	ldr r4, _081DA070 @ =0x085AE144
	movs r6, #6
_081DA042:
	ldr r0, [r4]
	bl IsMagicUnlocked
	cmp r0, #0
	beq _081DA05A
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r7, r1
	adds r0, r0, r5
	ldr r1, [r4]
	strb r1, [r0]
	adds r5, #1
_081DA05A:
	adds r4, #4
	subs r6, #1
	cmp r6, #0
	bge _081DA042
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r7, r1
	strh r5, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DA070: .4byte 0x085AE144

	thumb_func_start FUN_081da074
FUN_081da074: @ 0x081DA074
	push {lr}
	adds r2, r0, #0
	ldr r1, _081DA08C @ =0x00000286
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DA0A6
	cmp r0, #1
	bgt _081DA090
	cmp r0, #0
	beq _081DA096
	b _081DA0BC
	.align 2, 0
_081DA08C: .4byte 0x00000286
_081DA090:
	cmp r0, #2
	beq _081DA0B4
	b _081DA0BC
_081DA096:
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrh r1, [r0]
	subs r3, #1
	adds r0, r2, r3
	strb r1, [r0]
	b _081DA0BC
_081DA0A6:
	ldr r0, _081DA0B0 @ =0x0000028B
	adds r1, r2, r0
	movs r0, #2
	b _081DA0BA
	.align 2, 0
_081DA0B0: .4byte 0x0000028B
_081DA0B4:
	ldr r3, _081DA0C0 @ =0x0000028B
	adds r1, r2, r3
	movs r0, #1
_081DA0BA:
	strb r0, [r1]
_081DA0BC:
	pop {r0}
	bx r0
	.align 2, 0
_081DA0C0: .4byte 0x0000028B

	thumb_func_start FUN_081da0c4
FUN_081da0c4: @ 0x081DA0C4
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _081DA0FC @ =0x0000029D
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _081DA100 @ =0x00000286
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _081DA104 @ =0x030046A0
	ldr r1, [r0]
	subs r2, #0x48
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _081DA10C
	ldr r0, _081DA108 @ =0x00000289
	adds r1, r4, r0
	movs r0, #3
	b _081DA128
	.align 2, 0
_081DA0FC: .4byte 0x0000029D
_081DA100: .4byte 0x00000286
_081DA104: .4byte 0x030046A0
_081DA108: .4byte 0x00000289
_081DA10C:
	movs r2, #0x8e
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _081DA122
	adds r2, #0x51
	adds r1, r4, r2
	movs r0, #2
	b _081DA128
_081DA122:
	ldr r0, _081DA144 @ =0x00000289
	adds r1, r4, r0
	movs r0, #1
_081DA128:
	strb r0, [r1]
	ldr r2, _081DA148 @ =0x0000028A
	adds r1, r4, r2
	movs r0, #4
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_081da038
	adds r0, r4, #0
	bl FUN_081da074
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DA144: .4byte 0x00000289
_081DA148: .4byte 0x0000028A

	thumb_func_start FUN_081da14c
FUN_081da14c: @ 0x081DA14C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _081DA164 @ =0x0000029D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DA17C
	cmp r0, #1
	bgt _081DA168
	cmp r0, #0
	beq _081DA16E
	b _081DA1E0
	.align 2, 0
_081DA164: .4byte 0x0000029D
_081DA168:
	cmp r0, #2
	beq _081DA18C
	b _081DA1E0
_081DA16E:
	ldr r2, _081DA178 @ =0x00000286
	adds r0, r5, r2
	ldrb r1, [r0]
	b _081DA1E2
	.align 2, 0
_081DA178: .4byte 0x00000286
_081DA17C:
	ldr r1, _081DA188 @ =0x00000287
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r1, r0, #3
	b _081DA1E2
	.align 2, 0
_081DA188: .4byte 0x00000287
_081DA18C:
	ldr r2, _081DA1A0 @ =0x00000286
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DA1C0
	cmp r0, #1
	bgt _081DA1A4
	cmp r0, #0
	beq _081DA1AA
	b _081DA1E0
	.align 2, 0
_081DA1A0: .4byte 0x00000286
_081DA1A4:
	cmp r0, #2
	beq _081DA1C8
	b _081DA1E0
_081DA1AA:
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrb r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r1, r0, #7
	b _081DA1E2
_081DA1C0:
	ldr r1, _081DA1C4 @ =0x085AE160
	b _081DA1CA
	.align 2, 0
_081DA1C4: .4byte 0x085AE160
_081DA1C8:
	ldr r1, _081DA1DC @ =0x085AE168
_081DA1CA:
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r0, #7
	b _081DA1E2
	.align 2, 0
_081DA1DC: .4byte 0x085AE168
_081DA1E0:
	movs r1, #0
_081DA1E2:
	ldr r0, _081DA214 @ =0x0000029B
	adds r6, r5, r0
	movs r0, #0
	ldrsb r0, [r6, r0]
	adds r4, r1, #0
	adds r4, #0x19
	cmp r0, r4
	beq _081DA20E
	bl FUN_08049e5c
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl FUN_08049e30
	strb r4, [r6]
_081DA20E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DA214: .4byte 0x0000029B

	thumb_func_start FUN_081da218
FUN_081da218: @ 0x081DA218
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #0x9e
	lsls r0, r0, #2
	adds r4, r7, r0
	ldr r0, [r4]
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r5, r7, r1
	ldr r1, [r5]
	bl TextPanel_SetScript
	ldr r0, [r4]
	ldr r2, _081DA288 @ =0x00000286
	adds r6, r7, r2
	ldrb r1, [r6]
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	ldrb r1, [r6]
	movs r2, #0xa6
	lsls r2, r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	movs r0, #0x9f
	lsls r0, r0, #2
	adds r4, r7, r0
	ldr r0, [r4]
	ldr r1, [r5]
	bl TextPanel_SetScript
	ldr r0, [r4]
	ldr r1, _081DA28C @ =0x00000287
	adds r5, r7, r1
	ldrb r1, [r5]
	adds r1, #3
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	ldrb r1, [r5]
	ldr r2, _081DA290 @ =0x00000299
	adds r0, r7, r2
	strb r1, [r0]
	ldrb r0, [r6]
	cmp r0, #1
	beq _081DA2AE
	cmp r0, #1
	bgt _081DA294
	cmp r0, #0
	beq _081DA29A
	b _081DA2D0
	.align 2, 0
_081DA288: .4byte 0x00000286
_081DA28C: .4byte 0x00000287
_081DA290: .4byte 0x00000299
_081DA294:
	cmp r0, #2
	beq _081DA2B8
	b _081DA2D0
_081DA29A:
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r5, [r0]
	b _081DA2D2
_081DA2AE:
	ldr r1, _081DA2B4 @ =0x085AE160
	b _081DA2BA
	.align 2, 0
_081DA2B4: .4byte 0x085AE160
_081DA2B8:
	ldr r1, _081DA2CC @ =0x085AE168
_081DA2BA:
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	b _081DA2D2
	.align 2, 0
_081DA2CC: .4byte 0x085AE168
_081DA2D0:
	movs r5, #0
_081DA2D2:
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r4, r7, r0
	ldr r0, [r4]
	movs r2, #0x9c
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	adds r1, r5, #7
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r1, [r0]
	ldr r2, _081DA308 @ =0x0000029A
	adds r0, r7, r2
	strb r1, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DA308: .4byte 0x0000029A

	thumb_func_start FUN_081da30c
FUN_081da30c: @ 0x081DA30C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x12
	movs r1, #4
	movs r2, #0xa
	movs r3, #2
	bl TextPanel_Create
	movs r2, #0x9e
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0x12
	movs r1, #8
	movs r2, #0xa
	movs r3, #2
	bl TextPanel_Create
	movs r2, #0x9f
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0x10
	movs r1, #0xc
	movs r2, #0xc
	movs r3, #2
	bl TextPanel_Create
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	bl FUN_08049f5c
	bl FUN_08049e5c
	movs r2, #1
	movs r0, #0x9d
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r4, #0
	bl FUN_081da0c4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081da370
FUN_081da370: @ 0x081DA370
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	movs r1, #0x9f
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081da3a0
FUN_081da3a0: @ 0x081DA3A0
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r4, _081DA3EC @ =0x0000CB05
	ldr r1, _081DA3F0 @ =0x0000DCC1
	adds r0, r4, #0
	bl GetFile
	adds r1, r0, #0
	movs r2, #0x90
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x40
	adds r0, r5, r2
	bl OpenMainSpriteFile
	ldr r1, _081DA3F4 @ =0x00005D04
	adds r0, r4, #0
	bl GetFile
	adds r1, r0, #0
	movs r2, #0x91
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	subs r2, #0x24
	adds r0, r5, r2
	bl OpenMainSpriteFile
	movs r4, #0
_081DA3DE:
	cmp r4, #4
	bhi _081DA434
	lsls r0, r4, #2
	ldr r1, _081DA3F8 @ =_081DA3FC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081DA3EC: .4byte 0x0000CB05
_081DA3F0: .4byte 0x0000DCC1
_081DA3F4: .4byte 0x00005D04
_081DA3F8: .4byte _081DA3FC
_081DA3FC: @ jump table
	.4byte _081DA410 @ case 0
	.4byte _081DA418 @ case 1
	.4byte _081DA420 @ case 2
	.4byte _081DA428 @ case 3
	.4byte _081DA42C @ case 4
_081DA410:
	movs r2, #0x33
	movs r0, #0x80
	lsls r0, r0, #2
	b _081DA43A
_081DA418:
	movs r2, #0x34
	movs r0, #0x80
	lsls r0, r0, #2
	b _081DA43A
_081DA420:
	movs r2, #0x35
	movs r0, #0x80
	lsls r0, r0, #2
	b _081DA43A
_081DA428:
	movs r2, #0xb6
	b _081DA436
_081DA42C:
	movs r2, #0x15
	movs r0, #0x80
	lsls r0, r0, #2
	b _081DA43A
_081DA434:
	movs r2, #0
_081DA436:
	movs r0, #0x88
	lsls r0, r0, #2
_081DA43A:
	adds r3, r5, r0
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #5
	adds r0, #0x20
	adds r0, r5, r0
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	adds r1, r3, #0
	movs r3, #0x10
	bl MainSprite_Add
	adds r4, #1
	cmp r4, #4
	ble _081DA3DE
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081da468
FUN_081da468: @ 0x081DA468
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r7, #0
_081DA46E:
	cmp r7, #4
	bls _081DA474
	b _081DA5C0
_081DA474:
	lsls r0, r7, #2
	ldr r1, _081DA480 @ =_081DA484
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081DA480: .4byte _081DA484
_081DA484: @ jump table
	.4byte _081DA498 @ case 0
	.4byte _081DA4CC @ case 1
	.4byte _081DA50C @ case 2
	.4byte _081DA594 @ case 3
	.4byte _081DA5AC @ case 4
_081DA498:
	lsls r1, r7, #1
	adds r1, r1, r7
	lsls r1, r1, #5
	adds r1, r6, r1
	ldr r3, _081DA4C4 @ =0x085AE16C
	ldr r0, _081DA4C8 @ =0x0000029D
	adds r4, r6, r0
	ldrb r0, [r4]
	lsls r0, r0, #3
	adds r0, r0, r3
	ldr r2, [r0]
	adds r0, r1, #0
	adds r0, #0x40
	strh r2, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #3
	adds r3, #4
	adds r0, r0, r3
	ldr r0, [r0]
	adds r1, #0x42
	strh r0, [r1]
	b _081DA5C0
	.align 2, 0
_081DA4C4: .4byte 0x085AE16C
_081DA4C8: .4byte 0x0000029D
_081DA4CC:
	ldr r1, _081DA4FC @ =0x0000029D
	adds r0, r6, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _081DA4E0
	ldr r2, _081DA500 @ =0x00000289
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #1
	bls _081DA52E
_081DA4E0:
	cmp r1, #2
	bne _081DA4EE
	ldr r1, _081DA504 @ =0x0000028B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	bls _081DA52E
_081DA4EE:
	lsls r3, r7, #1
	adds r3, r3, r7
	lsls r3, r3, #5
	adds r4, r6, r3
	ldr r2, _081DA508 @ =0x085AE184
	b _081DA55A
	.align 2, 0
_081DA4FC: .4byte 0x0000029D
_081DA500: .4byte 0x00000289
_081DA504: .4byte 0x0000028B
_081DA508: .4byte 0x085AE184
_081DA50C:
	ldr r1, _081DA544 @ =0x0000029D
	adds r0, r6, r1
	ldrb r1, [r0]
	cmp r1, #0
	bne _081DA520
	ldr r2, _081DA548 @ =0x00000289
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #1
	bls _081DA52E
_081DA520:
	cmp r1, #2
	bne _081DA550
	ldr r1, _081DA54C @ =0x0000028B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	bhi _081DA550
_081DA52E:
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	adds r2, r6, #0
	adds r2, #0x28
	adds r2, r2, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	b _081DA5C0
	.align 2, 0
_081DA544: .4byte 0x0000029D
_081DA548: .4byte 0x00000289
_081DA54C: .4byte 0x0000028B
_081DA550:
	lsls r3, r7, #1
	adds r3, r3, r7
	lsls r3, r3, #5
	adds r4, r6, r3
	ldr r2, _081DA58C @ =0x085AE19C
_081DA55A:
	ldr r0, _081DA590 @ =0x0000029D
	adds r5, r6, r0
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r0, r0, r2
	ldr r1, [r0]
	adds r0, r4, #0
	adds r0, #0x40
	strh r1, [r0]
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r2, #4
	adds r0, r0, r2
	ldr r0, [r0]
	adds r4, #0x42
	strh r0, [r4]
	adds r2, r6, #0
	adds r2, #0x28
	adds r2, r2, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	b _081DA5C0
	.align 2, 0
_081DA58C: .4byte 0x085AE19C
_081DA590: .4byte 0x0000029D
_081DA594:
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	adds r0, r6, r0
	adds r2, r0, #0
	adds r2, #0x40
	movs r1, #0x48
	strh r1, [r2]
	adds r0, #0x42
	movs r1, #0x60
	strh r1, [r0]
	b _081DA5C0
_081DA5AC:
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #5
	adds r0, r6, r0
	adds r1, r0, #0
	adds r1, #0x40
	movs r2, #0
	strh r2, [r1]
	adds r0, #0x42
	strh r2, [r0]
_081DA5C0:
	adds r7, #1
	cmp r7, #4
	bgt _081DA5C8
	b _081DA46E
_081DA5C8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081da5d0
FUN_081da5d0: @ 0x081DA5D0
	push {lr}
	movs r3, #1
	adds r1, r0, #0
	adds r1, #0x28
	movs r2, #4
_081DA5DA:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _081DA5DA
	pop {r0}
	bx r0

	thumb_func_start FUN_081da5ec
FUN_081da5ec: @ 0x081DA5EC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x20
	movs r5, #4
_081DA5F4:
	adds r0, r4, #0
	bl MainSprite_Remove
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081DA5F4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081da608
FUN_081da608: @ 0x081DA608
	push {lr}
	mov ip, r0
	ldr r0, _081DA644 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _081DA648 @ =0x00005260
	adds r2, r0, r1
	movs r1, #0x92
	lsls r1, r1, #2
	add r1, ip
	movs r3, #0xf
_081DA61C:
	ldrh r0, [r2]
	strh r0, [r1]
	adds r2, #2
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _081DA61C
	movs r0, #0x92
	lsls r0, r0, #2
	add r0, ip
	mov r1, ip
	str r0, [r1, #0x68]
	movs r1, #0x9a
	lsls r1, r1, #2
	add r1, ip
	movs r0, #0
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_081DA644: .4byte 0x03003584
_081DA648: .4byte 0x00005260

	thumb_func_start FUN_081da64c
FUN_081da64c: @ 0x081DA64C
	push {lr}
	adds r3, r0, #0
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrh r0, [r0]
	movs r2, #0x1f
	cmp r0, #9
	bls _081DA678
	movs r2, #0x1b
	cmp r0, #0x11
	bls _081DA678
	movs r2, #0x12
	cmp r0, #0x19
	bls _081DA678
	movs r2, #0xa
	cmp r0, #0x21
	bls _081DA678
	movs r2, #0x1b
	cmp r0, #0x29
	bhi _081DA678
	movs r2, #0x12
_081DA678:
	movs r0, #0x9a
	lsls r0, r0, #2
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x31
	bls _081DA690
	movs r0, #0
	strh r0, [r1]
_081DA690:
	movs r1, #0x98
	lsls r1, r1, #2
	adds r0, r3, r1
	strh r2, [r0]
	pop {r0}
	bx r0

	thumb_func_start FUN_081da69c
FUN_081da69c: @ 0x081DA69C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r2, [r0]
	adds r1, #0x12
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r2, r0
	beq _081DA724
	subs r1, #0x14
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DA6DC
	cmp r0, #1
	bgt _081DA6CA
	cmp r0, #0
	beq _081DA6D0
	b _081DA6F4
_081DA6CA:
	cmp r0, #2
	beq _081DA6E4
	b _081DA6F4
_081DA6D0:
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r6, r1
	adds r0, r0, r2
	ldrb r5, [r0]
	b _081DA6F6
_081DA6DC:
	ldr r1, _081DA6E0 @ =0x085AE160
	b _081DA6E6
	.align 2, 0
_081DA6E0: .4byte 0x085AE160
_081DA6E4:
	ldr r1, _081DA6F0 @ =0x085AE168
_081DA6E6:
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r5, [r0]
	b _081DA6F6
	.align 2, 0
_081DA6F0: .4byte 0x085AE168
_081DA6F4:
	movs r5, #0
_081DA6F6:
	movs r2, #0xa0
	lsls r2, r2, #2
	adds r4, r6, r2
	ldr r0, [r4]
	subs r2, #0x10
	adds r1, r6, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	adds r1, r5, #7
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r1, [r0]
	ldr r2, _081DA72C @ =0x0000029A
	adds r0, r6, r2
	strb r1, [r0]
_081DA724:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DA72C: .4byte 0x0000029A

	thumb_func_start FUN_081da730
FUN_081da730: @ 0x081DA730
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r1, _081DA74C @ =0x0000029D
	adds r0, r5, r1
	ldrb r7, [r0]
	cmp r7, #1
	beq _081DA7C0
	cmp r7, #1
	bgt _081DA750
	cmp r7, #0
	beq _081DA756
	b _081DA80A
	.align 2, 0
_081DA74C: .4byte 0x0000029D
_081DA750:
	cmp r7, #2
	beq _081DA804
	b _081DA80A
_081DA756:
	ldr r2, _081DA7B8 @ =0x00000286
	adds r6, r5, r2
	ldrb r1, [r6]
	movs r0, #0xa6
	lsls r0, r0, #2
	adds r0, r0, r5
	mov r8, r0
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	beq _081DA80A
	movs r1, #0x9e
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r0, [r4]
	subs r2, #0x16
	adds r1, r5, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	ldrb r1, [r6]
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	ldrb r0, [r6]
	mov r1, r8
	strb r0, [r1]
	ldr r2, _081DA7BC @ =0x0000029A
	adds r1, r5, r2
	movs r0, #0xff
	strb r0, [r1]
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r7, [r0]
	adds r0, r5, #0
	bl FUN_081da074
	adds r0, r5, #0
	bl FUN_081da69c
	adds r0, r5, #0
	bl FUN_081da814
	b _081DA80A
	.align 2, 0
_081DA7B8: .4byte 0x00000286
_081DA7BC: .4byte 0x0000029A
_081DA7C0:
	ldr r2, _081DA7FC @ =0x00000287
	adds r6, r5, r2
	ldrb r1, [r6]
	ldr r0, _081DA800 @ =0x00000299
	adds r7, r5, r0
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r1, r0
	beq _081DA80A
	movs r1, #0x9f
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r0, [r4]
	subs r2, #0x17
	adds r1, r5, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	ldrb r1, [r6]
	adds r1, #3
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	ldrb r0, [r6]
	strb r0, [r7]
	b _081DA80A
	.align 2, 0
_081DA7FC: .4byte 0x00000287
_081DA800: .4byte 0x00000299
_081DA804:
	adds r0, r5, #0
	bl FUN_081da69c
_081DA80A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081da814
FUN_081da814: @ 0x081DA814
	push {r4, lr}
	adds r3, r0, #0
	ldr r1, _081DA82C @ =0x00000286
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DA84A
	cmp r0, #1
	bgt _081DA830
	cmp r0, #0
	beq _081DA836
	b _081DA870
	.align 2, 0
_081DA82C: .4byte 0x00000286
_081DA830:
	cmp r0, #2
	beq _081DA858
	b _081DA870
_081DA836:
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r1, r3, r2
	movs r4, #0xa4
	lsls r4, r4, #2
	adds r0, r3, r4
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r2, [r0]
	b _081DA872
_081DA84A:
	ldr r1, _081DA854 @ =0x085AE160
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r0, r3, r2
	b _081DA860
	.align 2, 0
_081DA854: .4byte 0x085AE160
_081DA858:
	ldr r1, _081DA86C @ =0x085AE168
	movs r4, #0xa2
	lsls r4, r4, #2
	adds r0, r3, r4
_081DA860:
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	b _081DA872
	.align 2, 0
_081DA86C: .4byte 0x085AE168
_081DA870:
	movs r2, #0
_081DA872:
	adds r2, #0xb6
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r4, #0x88
	lsls r4, r4, #2
	adds r1, r3, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081da890
FUN_081da890: @ 0x081DA890
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081DA8AC
	ldr r1, _081DA8D0 @ =0x0000029E
	adds r0, r5, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081DA8AC:
	ldr r0, _081DA8D0 @ =0x0000029E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0xa
	bne _081DA8C2
	adds r0, r5, #0
	bl FUN_081d9da4
	adds r0, r5, #0
	bl FUN_081d9ef4
_081DA8C2:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DA8D0: .4byte 0x0000029E

	thumb_func_start FUN_081da8d4
FUN_081da8d4: @ 0x081DA8D4
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081DA908
	movs r0, #4
	str r0, [sp]
	ldr r0, _081DA928 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _081DA92C @ =0x0000029E
	adds r0, r5, r1
	movs r1, #0
	strh r4, [r0]
	strb r1, [r6]
_081DA908:
	ldr r0, _081DA92C @ =0x0000029E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x14
	bne _081DA918
	adds r0, r5, #0
	bl FUN_081d9f3c
_081DA918:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DA928: .4byte 0x0000FFFF
_081DA92C: .4byte 0x0000029E

	thumb_func_start FUN_081da930
FUN_081da930: @ 0x081DA930
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081DA97A
	bl FUN_08049e5c
	ldr r1, _081DA998 @ =0x00000286
	adds r0, r5, r1
	ldrb r4, [r0]
	movs r3, #0x9c
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	adds r4, #0x19
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl FUN_08049e30
	adds r0, r5, #0
	bl FUN_081da730
	ldr r1, _081DA99C @ =0x0000029D
	adds r0, r5, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081DA9A0 @ =0x0000029E
	adds r0, r5, r3
	movs r1, #0
	strh r2, [r0]
	strb r1, [r6]
_081DA97A:
	ldr r0, _081DA9A0 @ =0x0000029E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x1d
	bhi _081DA9A4
	adds r0, r5, #0
	bl FUN_081da64c
	adds r0, r5, #0
	bl FUN_081da14c
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _081DAC98
	.align 2, 0
_081DA998: .4byte 0x00000286
_081DA99C: .4byte 0x0000029D
_081DA9A0: .4byte 0x0000029E
_081DA9A4:
	ldr r1, _081DA9C0 @ =0x0000029D
	adds r0, r5, r1
	ldrb r4, [r0]
	ldr r3, _081DA9C4 @ =0x00000285
	adds r6, r5, r3
	movs r3, #0
	ldr r1, _081DA9C8 @ =0x030044E0
	ldrh r2, [r1, #2]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _081DA9CC
	movs r3, #1
	b _081DAA06
	.align 2, 0
_081DA9C0: .4byte 0x0000029D
_081DA9C4: .4byte 0x00000285
_081DA9C8: .4byte 0x030044E0
_081DA9CC:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _081DA9D8
	movs r3, #2
	b _081DAA06
_081DA9D8:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081DA9E4
	movs r3, #4
	b _081DAA06
_081DA9E4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081DA9F0
	movs r3, #8
	b _081DAA06
_081DA9F0:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081DA9FC
	movs r3, #0x20
	b _081DAA06
_081DA9FC:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081DAA06
	movs r3, #0x10
_081DAA06:
	ldrh r2, [r1]
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0
	beq _081DAA4E
	ldrb r0, [r6]
	cmp r0, #0xb
	bls _081DAA4C
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	beq _081DAA22
	movs r0, #1
	b _081DAA2C
_081DAA22:
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _081DAA2E
	movs r0, #2
_081DAA2C:
	orrs r3, r0
_081DAA2E:
	ldrh r1, [r1]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _081DAA3C
	movs r0, #4
	b _081DAA46
_081DAA3C:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081DAA48
	movs r0, #8
_081DAA46:
	orrs r3, r0
_081DAA48:
	movs r0, #0
	b _081DAA4E
_081DAA4C:
	adds r0, #1
_081DAA4E:
	strb r0, [r6]
	movs r6, #1
	adds r0, r3, #0
	ands r0, r6
	cmp r0, #0
	beq _081DAA70
	cmp r4, #0
	bne _081DAA62
	movs r4, #2
	b _081DAA64
_081DAA62:
	subs r4, #1
_081DAA64:
	ldr r0, _081DAA6C @ =0x00000285
	adds r1, r5, r0
	b _081DABEC
	.align 2, 0
_081DAA6C: .4byte 0x00000285
_081DAA70:
	movs r2, #2
	adds r0, r3, #0
	ands r0, r2
	cmp r0, #0
	beq _081DAA86
	cmp r4, #2
	bne _081DAA82
	movs r4, #0
	b _081DABE8
_081DAA82:
	adds r4, #1
	b _081DABE8
_081DAA86:
	movs r0, #4
	ands r0, r3
	cmp r0, #0
	beq _081DAB54
	ldr r1, _081DAAA4 @ =0x0000029D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DAAD8
	cmp r0, #1
	bgt _081DAAA8
	cmp r0, #0
	beq _081DAAAE
	b _081DAB42
	.align 2, 0
_081DAAA4: .4byte 0x0000029D
_081DAAA8:
	cmp r0, #2
	beq _081DAB0C
	b _081DAB42
_081DAAAE:
	ldr r3, _081DAAC4 @ =0x00000286
	adds r0, r5, r3
	ldrb r2, [r0]
	cmp r2, #0
	bne _081DAACC
	ldr r1, _081DAAC8 @ =0x00000289
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r1, r0, #1
	b _081DAACE
	.align 2, 0
_081DAAC4: .4byte 0x00000286
_081DAAC8: .4byte 0x00000289
_081DAACC:
	subs r1, r2, #1
_081DAACE:
	ldr r3, _081DAAD4 @ =0x00000286
	b _081DAAF8
	.align 2, 0
_081DAAD4: .4byte 0x00000286
_081DAAD8:
	ldr r1, _081DAAEC @ =0x00000287
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #0
	bne _081DAAF4
	ldr r3, _081DAAF0 @ =0x0000028A
	adds r0, r5, r3
	ldrb r0, [r0]
	subs r1, r0, #1
	b _081DAAF6
	.align 2, 0
_081DAAEC: .4byte 0x00000287
_081DAAF0: .4byte 0x0000028A
_081DAAF4:
	subs r1, r2, #1
_081DAAF6:
	ldr r3, _081DAB08 @ =0x00000287
_081DAAF8:
	adds r0, r5, r3
	strb r1, [r0]
	cmp r2, r1
	beq _081DAB42
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081DAB42
	.align 2, 0
_081DAB08: .4byte 0x00000287
_081DAB0C:
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r2, [r0]
	cmp r2, #0
	bne _081DAB28
	ldr r3, _081DAB24 @ =0x0000028B
	adds r0, r5, r3
	ldrb r0, [r0]
	subs r1, r0, #1
	b _081DAB2A
	.align 2, 0
_081DAB24: .4byte 0x0000028B
_081DAB28:
	subs r1, r2, #1
_081DAB2A:
	movs r3, #0xa2
	lsls r3, r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	cmp r2, r1
	beq _081DAB3C
	movs r0, #0xdc
	bl PlaySound_082406e0
_081DAB3C:
	adds r0, r5, #0
	bl FUN_081da814
_081DAB42:
	adds r0, r5, #0
	bl FUN_081da730
	ldr r0, _081DAB50 @ =0x00000285
	adds r1, r5, r0
	b _081DABEC
	.align 2, 0
_081DAB50: .4byte 0x00000285
_081DAB54:
	movs r0, #8
	ands r0, r3
	cmp r0, #0
	beq _081DABFC
	ldr r1, _081DAB70 @ =0x0000029D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DAB8C
	cmp r0, #1
	bgt _081DAB74
	cmp r0, #0
	beq _081DAB7A
	b _081DABE2
	.align 2, 0
_081DAB70: .4byte 0x0000029D
_081DAB74:
	cmp r0, #2
	beq _081DABB8
	b _081DABE2
_081DAB7A:
	ldr r0, _081DAB84 @ =0x00000286
	adds r3, r5, r0
	ldrb r2, [r3]
	ldr r1, _081DAB88 @ =0x00000289
	b _081DAB94
	.align 2, 0
_081DAB84: .4byte 0x00000286
_081DAB88: .4byte 0x00000289
_081DAB8C:
	ldr r0, _081DABB0 @ =0x00000287
	adds r3, r5, r0
	ldrb r2, [r3]
	ldr r1, _081DABB4 @ =0x0000028A
_081DAB94:
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r0, #1
	adds r1, r2, #1
	cmp r2, r0
	bne _081DABA2
	movs r1, #0
_081DABA2:
	strb r1, [r3]
	cmp r2, r1
	beq _081DABE2
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081DABE2
	.align 2, 0
_081DABB0: .4byte 0x00000287
_081DABB4: .4byte 0x0000028A
_081DABB8:
	movs r0, #0xa2
	lsls r0, r0, #2
	adds r3, r5, r0
	ldrb r2, [r3]
	ldr r1, _081DABF4 @ =0x0000028B
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r0, #1
	adds r1, r2, #1
	cmp r2, r0
	bne _081DABD0
	movs r1, #0
_081DABD0:
	strb r1, [r3]
	cmp r2, r1
	beq _081DABDC
	movs r0, #0xdc
	bl PlaySound_082406e0
_081DABDC:
	adds r0, r5, #0
	bl FUN_081da814
_081DABE2:
	adds r0, r5, #0
	bl FUN_081da730
_081DABE8:
	ldr r3, _081DABF8 @ =0x00000285
	adds r1, r5, r3
_081DABEC:
	movs r0, #0
	strb r0, [r1]
	b _081DAC74
	.align 2, 0
_081DABF4: .4byte 0x0000028B
_081DABF8: .4byte 0x00000285
_081DABFC:
	movs r0, #0x20
	ands r0, r3
	cmp r0, #0
	beq _081DAC28
	ldr r1, _081DAC24 @ =FUN_081da890
	movs r3, #0x9b
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r6, [r0]
	adds r3, #0x18
	adds r0, r5, r3
	strb r2, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081DAC98
	.align 2, 0
_081DAC24: .4byte FUN_081da890
_081DAC28:
	movs r0, #0x10
	ands r3, r0
	cmp r3, #0
	beq _081DAC74
	ldr r0, _081DAC44 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DAC48
	adds r0, #0x56
	ldrb r0, [r0]
	cmp r0, #1
	bne _081DAC48
	movs r0, #1
	b _081DAC4A
	.align 2, 0
_081DAC44: .4byte 0x03002C68
_081DAC48:
	movs r0, #0
_081DAC4A:
	cmp r0, #0
	bne _081DAC74
	ldr r1, _081DAC70 @ =FUN_081da8d4
	movs r2, #1
	movs r3, #0x9b
	lsls r3, r3, #2
	adds r0, r5, r3
	str r1, [r0]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	adds r3, #0x18
	adds r0, r5, r3
	strb r2, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081DAC98
	.align 2, 0
_081DAC70: .4byte FUN_081da8d4
_081DAC74:
	ldr r0, _081DACA0 @ =0x0000029D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, r4
	beq _081DAC8C
	strb r4, [r1]
	adds r0, r5, #0
	bl FUN_081da468
	movs r0, #0xdc
	bl PlaySound_082406e0
_081DAC8C:
	adds r0, r5, #0
	bl FUN_081da64c
	adds r0, r5, #0
	bl FUN_081da14c
_081DAC98:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DACA0: .4byte 0x0000029D

	thumb_func_start Entity7999_Update
Entity7999_Update: @ 0x081DACA4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dfa04
	cmp r0, #0
	bne _081DACC6
	bl FUN_08049fa8
	adds r0, r4, #0
	bl FUN_081da5d0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #1
	rsbs r0, r0, #0
	b _081DACDA
_081DACC6:
	movs r1, #0x9b
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081DACD8
	adds r0, r4, #0
	bl _call_via_r1
_081DACD8:
	movs r0, #1
_081DACDA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start Entity7999_Destroy
Entity7999_Destroy: @ 0x081DACE0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081da5ec
	adds r0, r4, #0
	bl FUN_081da370
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity7999_Init
Entity7999_Init: @ 0x081DACF8
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081DAD1E
	bl FUN_0823d340
	movs r2, #0x9c
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
	cmp r0, #0
	bne _081DAD1E
	movs r0, #1
	rsbs r0, r0, #0
	b _081DAE0E
_081DAD1E:
	movs r0, #0x6c
	movs r1, #0
	bl VM_GetKeywordValue
	movs r3, #0xa8
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r4, #0
	strh r0, [r1]
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, _081DAE18 @ =0x000002A2
	adds r1, r5, r2
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_081d9f8c
	adds r0, r5, #0
	bl FUN_081da30c
	adds r0, r5, #0
	bl FUN_081da3a0
	adds r0, r5, #0
	bl FUN_081da468
	adds r0, r5, #0
	bl FUN_081da608
	ldr r3, _081DAE1C @ =0x0000029B
	adds r1, r5, r3
	movs r0, #0xff
	strb r0, [r1]
	movs r0, #0xa6
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	ldr r2, _081DAE20 @ =0x00000299
	adds r1, r5, r2
	strb r0, [r1]
	subs r3, #1
	adds r1, r5, r3
	strb r0, [r1]
	ldr r1, _081DAE24 @ =FUN_081da930
	subs r2, #0x2d
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081DADB8
	movs r0, #4
	str r0, [sp]
	ldr r0, _081DAE28 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_081DADB8:
	movs r0, #7
	bl FUN_0809c08c
	ldr r0, _081DAE2C @ =0x03002C68
	ldr r0, [r0]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r2, r0, r3
	cmp r0, #0
	bne _081DADCE
	movs r2, #0
_081DADCE:
	adds r0, r2, #0
	adds r0, #0x40
	ldrb r1, [r0]
	ldr r3, _081DAE30 @ =0x00000286
	adds r0, r5, r3
	strb r1, [r0]
	adds r0, r2, #0
	adds r0, #0x41
	ldrb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r0, r2, #0
	adds r0, #0x42
	ldrb r1, [r0]
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r5, #0
	bl FUN_081d9e50
	adds r0, r5, #0
	bl FUN_081da814
	adds r0, r5, #0
	bl FUN_081da074
	adds r0, r5, #0
	bl FUN_081da218
	movs r0, #1
_081DAE0E:
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081DAE18: .4byte 0x000002A2
_081DAE1C: .4byte 0x0000029B
_081DAE20: .4byte 0x00000299
_081DAE24: .4byte FUN_081da930
_081DAE28: .4byte 0x0000FFFF
_081DAE2C: .4byte 0x03002C68
_081DAE30: .4byte 0x00000286

	thumb_func_start Entity7999_Create
Entity7999_Create: @ 0x081DAE34
	push {r4, lr}
	movs r1, #0xa9
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081DAE6C
	ldr r1, _081DAE64 @ =Entity7999_Update
	ldr r2, _081DAE68 @ =Entity7999_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity7999_Init
	cmp r0, #0
	bge _081DAE6C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081DAE6E
	.align 2, 0
_081DAE64: .4byte Entity7999_Update
_081DAE68: .4byte Entity7999_Destroy
_081DAE6C:
	adds r0, r4, #0
_081DAE6E:
	pop {r4}
	pop {r1}
	bx r1
