	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08013288
FUN_08013288: @ 0x08013288
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r6, r4, #0
	bl FUN_08236524
	ldrh r1, [r5, #0x3e]
	cmp r1, #0
	beq _080132E8
	ldrb r0, [r4, #0x1a]
	cmp r0, #0
	bne _080132AE
	movs r0, #0xa
	strb r0, [r4, #0x1e]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080132E4
_080132AE:
	ldrh r0, [r4, #0x1c]
	subs r0, r0, r1
	strh r0, [r4, #0x1c]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _080132CC
	movs r0, #1
	strb r0, [r4, #0x1b]
	movs r0, #0
	str r0, [r4, #0x20]
	movs r0, #0xa5
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080132E4
_080132CC:
	movs r0, #0xa
	strb r0, [r6, #0x1e]
	adds r0, r6, #0
	adds r0, #0x90
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080132E4:
	movs r0, #0
	strh r0, [r5, #0x3e]
_080132E8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080132f0
FUN_080132f0: @ 0x080132F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldrb r0, [r7, #0x1b]
	cmp r0, #0
	bne _0801339C
	ldrb r0, [r7, #0x1e]
	cmp r0, #0
	bne _0801330C
	b _0801340C
_0801330C:
	adds r6, r7, #0
	adds r6, #0xc8
	ldr r0, [r7, #0x28]
	ldr r1, [r7, #0x2c]
	str r0, [r6]
	str r1, [r6, #4]
	ldrb r0, [r7, #0x1e]
	subs r0, #1
	strb r0, [r7, #0x1e]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08013346
	ldrb r0, [r7, #0x1a]
	cmp r0, #1
	bne _08013336
	adds r0, r7, #0
	adds r0, #0x90
	movs r1, #0xa2
	lsls r1, r1, #2
	bl FUN_0822b20c
_08013336:
	adds r0, r7, #0
	adds r0, #0x30
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
	b _0801340C
_08013346:
	ldr r0, _08013390 @ =0x0203B400
	mov sb, r0
	ldr r0, _08013394 @ =0x030046B8
	mov r8, r0
	ldr r1, [r0]
	adds r1, #1
	ldr r3, _08013398 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	add r0, sb
	ldrh r2, [r0]
	ldrh r0, [r6]
	subs r0, #8
	movs r4, #0xf
	ands r2, r4
	adds r0, r0, r2
	strh r0, [r6]
	adds r1, #1
	ands r1, r3
	mov r0, r8
	str r1, [r0]
	lsls r1, r1, #1
	add r1, sb
	ldrh r1, [r1]
	adds r2, r7, #0
	adds r2, #0xcc
	ldrh r0, [r2]
	subs r0, #8
	ands r1, r4
	adds r0, r0, r1
	strh r0, [r2]
	subs r2, #0x9c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	b _0801340C
	.align 2, 0
_08013390: .4byte 0x0203B400
_08013394: .4byte 0x030046B8
_08013398: .4byte 0x000003FF
_0801339C:
	adds r5, r7, #0
	adds r5, #0x28
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0x10
	str r0, [sp, #4]
	movs r4, #8
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0
	mov sb, r0
	str r0, [sp, #0x10]
	movs r0, #0x80
	lsls r0, r0, #1
	mov r8, r0
	str r0, [sp, #0x14]
	movs r0, #0x18
	mov sl, r0
	str r0, [sp, #0x18]
	movs r0, #0x10
	str r0, [sp, #0x1c]
	movs r0, #3
	movs r1, #4
	adds r2, r5, #0
	movs r3, #0x3c
	bl FUN_08014da0
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0x16
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, sb
	str r0, [sp, #0x10]
	mov r0, r8
	str r0, [sp, #0x14]
	mov r0, sl
	str r0, [sp, #0x18]
	movs r0, #0x10
	str r0, [sp, #0x1c]
	movs r0, #8
	movs r1, #8
	adds r2, r5, #0
	movs r3, #0x3c
	bl FUN_08014da0
	ldr r0, [r7, #0x24]
	cmp r0, #0
	beq _08013406
	movs r1, #0
	bl Script_ExecById
_08013406:
	adds r0, r7, #0
	bl KillEntity
_0801340C:
	ldr r0, [r7, #0x20]
	adds r0, #1
	str r0, [r7, #0x20]
	movs r0, #0
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08013424
FUN_08013424: @ 0x08013424
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x30
	bl FUN_08236424
	adds r0, r4, #0
	adds r0, #0x80
	bl FUN_082342a8
	adds r0, r4, #0
	adds r0, #0xac
	bl FUN_0822a4e0
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08013448
FUN_08013448: @ 0x08013448
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	movs r4, #0
	strh r1, [r6, #0x18]
	movs r0, #0x74
	movs r1, #0
	bl Script_GetKeywordValue
	strb r0, [r6, #0x1a]
	strb r4, [r6, #0x1b]
	movs r0, #0x6c
	movs r1, #0x32
	bl Script_GetKeywordValue
	strh r0, [r6, #0x1c]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08013484
	bl Script_GetValue
	strh r0, [r6, #0x28]
	bl Script_GetValue
	strh r0, [r6, #0x2a]
	bl Script_GetValue
	b _08013488
_08013484:
	strh r0, [r6, #0x28]
	strh r0, [r6, #0x2a]
_08013488:
	strh r0, [r6, #0x2c]
	movs r0, #0x65
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [r6, #0x24]
	adds r4, r6, #0
	adds r4, #0x90
	ldr r1, _080134AC @ =0x00002567
	adds r0, r4, #0
	bl FUN_0822b16c
	cmp r0, #0
	bne _080134B0
	movs r0, #1
	rsbs r0, r0, #0
	b _080135E6
	.align 2, 0
_080134AC: .4byte 0x00002567
_080134B0:
	adds r0, r6, #0
	adds r0, #0xac
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r2, r6, #0
	adds r2, #0xc8
	ldr r0, [r6, #0x28]
	ldr r1, [r6, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	ldrb r0, [r6, #0x1a]
	cmp r0, #1
	bne _080134DA
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r4, #0
	bl FUN_0822b20c
	b _080134E2
_080134DA:
	ldr r1, _08013578 @ =0x00000287
	adds r0, r4, #0
	bl FUN_0822b20c
_080134E2:
	adds r4, r6, #0
	adds r4, #0x30
	ldr r2, _0801357C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x82
	orrs r0, r3
	ldr r1, _08013580 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldrh r1, [r6, #0x18]
	ldr r2, _08013584 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823646c
	adds r5, r6, #0
	adds r5, #0x28
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236514
	ldr r1, _08013588 @ =FUN_08013288
	adds r0, r4, #0
	adds r2, r6, #0
	bl FUN_0823651c
	adds r0, r4, #0
	bl FUN_08236400
	ldrh r0, [r6, #0x28]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08013572
	cmp r1, #0
	blt _08013572
	ldr r0, _0801358C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08013572
	ldr r0, _08013590 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08013594
_08013572:
	movs r4, #0
	b _080135A2
	.align 2, 0
_08013578: .4byte 0x00000287
_0801357C: .4byte 0xFFFF0000
_08013580: .4byte 0x0000FFFF
_08013584: .4byte 0x00004001
_08013588: .4byte FUN_08013288
_0801358C: .4byte 0x030046A8
_08013590: .4byte 0x030046AC
_08013594:
	ldr r0, _080135B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080135A2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080135B8
	adds r0, #4
	b _080135C4
	.align 2, 0
_080135B4: .4byte 0x030046A4
_080135B8:
	ldr r0, _080135F0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080135C4:
	ldrb r0, [r0]
	movs r3, #0xf
	ands r3, r0
	cmp r3, #0xe
	bgt _080135D0
	adds r3, #1
_080135D0:
	adds r0, r6, #0
	adds r0, #0x80
	movs r1, #0xff
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	adds r1, r4, #0
	movs r2, #0
	bl FUN_08234270
	movs r0, #0
_080135E6:
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080135F0: .4byte 0x030046A4

	thumb_func_start FUN_080135f4
FUN_080135f4: @ 0x080135F4
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #8
	movs r1, #0xd8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801362C
	ldr r1, _08013624 @ =0x080132F1
	ldr r2, _08013628 @ =FUN_08013424
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08013448
	cmp r0, #0
	bge _0801362C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801362E
	.align 2, 0
_08013624: .4byte 0x080132F1
_08013628: .4byte FUN_08013424
_0801362C:
	adds r0, r4, #0
_0801362E:
	pop {r4, r5}
	pop {r1}
	bx r1

