	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start Dvalinn_Update
Dvalinn_Update: @ 0x082001A4
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #4
	ldr r0, _082001E8 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _082001DE
	adds r0, r4, #0
	bl FUN_08022e20
	adds r0, r4, #0
	bl FUN_081ffd9c
	adds r0, r4, #0
	bl FUN_081fc86c
	adds r0, r4, #0
	bl FUN_081ff740
	adds r0, r4, #0
	bl FUN_081ff734
	adds r0, r4, #0
	bl FUN_08022ec0
	adds r0, r4, #0
	bl FUN_081ffdb0
_082001DE:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_082001E8: .4byte 0x03002BC0

	thumb_func_start Dvalinn_Destroy
Dvalinn_Destroy: @ 0x082001EC
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08236424
	movs r1, #0x8f
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	adds r0, r4, #0
	bl FUN_08022b04
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	movs r1, #0xc7
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822f1c0
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_0822a4e0
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start Dvalinn_Init
Dvalinn_Init: @ 0x08200230
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	adds r7, r0, #0
	str r1, [sp, #0x1c]
	adds r6, r7, #0
	movs r0, #0x74
	movs r1, #3
	bl Script_GetKeywordValue
	mov sl, r0
	adds r0, r7, #0
	mov r1, sl
	bl FUN_08022a0c
	ldr r0, _08200274 @ =0x03002BE0
	ldr r2, [r0]
	cmp r2, #0
	beq _08200278
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r7, r1
	str r2, [r0]
	movs r4, #0x86
	lsls r4, r4, #1
	adds r1, r7, r4
	adds r0, r2, #0
	adds r0, #0x2c
	str r0, [r1]
	b _08200288
	.align 2, 0
_08200274: .4byte 0x03002BE0
_08200278:
	movs r5, #0x82
	lsls r5, r5, #1
	adds r0, r7, r5
	str r2, [r0]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r7, r1
	str r2, [r0]
_08200288:
	ldr r0, _08200324 @ =0x0000CB05
	ldr r1, _08200328 @ =0x0000D40A
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	bne _08200298
	b _082006E8
_08200298:
	movs r2, #0x87
	lsls r2, r2, #2
	adds r2, r2, r7
	mov r8, r2
	adds r1, r3, #0
	ldm r1!, {r0, r4, r5}
	stm r2!, {r0, r4, r5}
	ldm r1!, {r0, r4, r5}
	stm r2!, {r0, r4, r5}
	ldm r1!, {r4, r5}
	stm r2!, {r4, r5}
	mov r0, r8
	adds r1, r3, #0
	bl OpenSpriteSetFile
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08200380
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _0820032C @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r5
	orrs r1, r0
	str r1, [sp, #0x14]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08200330 @ =0x0000FFFF
	ldr r1, [sp, #0x14]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x14]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r4, sp, #0x14
	ldr r1, [r4, #4]
	ands r1, r5
	orrs r1, r0
	str r1, [r4, #4]
	bl Script_GetValue
	mov sb, r0
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0820031E
	cmp r1, #0
	blt _0820031E
	ldr r0, _08200334 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0820031E
	ldr r0, _08200338 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0820033C
_0820031E:
	movs r4, #0
	b _0820034A
	.align 2, 0
_08200324: .4byte 0x0000CB05
_08200328: .4byte 0x0000D40A
_0820032C: .4byte 0xFFFF0000
_08200330: .4byte 0x0000FFFF
_08200334: .4byte 0x030046A8
_08200338: .4byte 0x030046AC
_0820033C:
	ldr r0, _0820035C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0820034A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08200360
	adds r0, #4
	b _0820036C
	.align 2, 0
_0820035C: .4byte 0x030046A4
_08200360:
	ldr r0, _0820037C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0820036C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, sp
	strh r0, [r1, #0x16]
	b _08200396
	.align 2, 0
_0820037C: .4byte 0x030046A4
_08200380:
	ldr r0, _082003B4 @ =0x030046A0
	ldr r2, [r0]
	ldrh r0, [r2, #0x30]
	add r1, sp, #0x14
	strh r0, [r1]
	ldrh r0, [r2, #0x32]
	strh r0, [r1, #2]
	ldrh r0, [r2, #0x34]
	strh r0, [r1, #4]
	movs r2, #0x40
	mov sb, r2
_08200396:
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _082003B8
	bl Script_GetValue
	adds r5, r0, #0
	bl Script_GetValue
	mov r8, r0
	bl Script_GetValue
	b _082003C2
	.align 2, 0
_082003B4: .4byte 0x030046A0
_082003B8:
	movs r5, #0xfa
	lsls r5, r5, #3
	movs r4, #0x64
	mov r8, r4
	movs r0, #0x64
_082003C2:
	str r0, [sp, #0x24]
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _0820043C
	bl Script_GetValue
	ldr r2, _08200428 @ =0x000007E2
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r4, _0820042C @ =0x000007E4
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _08200430 @ =0x000007E6
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	str r0, [sp, #0x20]
	bl Script_GetValue
	adds r4, #4
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _08200434 @ =0x000007EA
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	adds r4, #4
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _08200438 @ =0x000007EE
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	adds r4, #4
	adds r1, r7, r4
	strh r0, [r1]
	b _0820048A
	.align 2, 0
_08200428: .4byte 0x000007E2
_0820042C: .4byte 0x000007E4
_08200430: .4byte 0x000007E6
_08200434: .4byte 0x000007EA
_08200438: .4byte 0x000007EE
_0820043C:
	ldr r1, _082004A4 @ =0x000007E2
	adds r0, r7, r1
	movs r1, #0x64
	strh r1, [r0]
	ldr r2, _082004A8 @ =0x000007E4
	adds r0, r7, r2
	strh r1, [r0]
	ldr r4, _082004AC @ =0x000007E6
	adds r0, r7, r4
	strh r1, [r0]
	movs r0, #0x64
	str r0, [sp, #0x20]
	movs r1, #0xfd
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r2, sp
	ldrh r2, [r2, #0x20]
	strh r2, [r0]
	adds r4, #4
	adds r0, r7, r4
	mov r1, sp
	ldrh r1, [r1, #0x20]
	strh r1, [r0]
	ldr r2, _082004B0 @ =0x000007EC
	adds r0, r7, r2
	mov r4, sp
	ldrh r4, [r4, #0x20]
	strh r4, [r0]
	ldr r1, _082004B4 @ =0x000007EE
	adds r0, r7, r1
	mov r2, sp
	ldrh r2, [r2, #0x20]
	strh r2, [r0]
	movs r4, #0xfe
	lsls r4, r4, #3
	adds r0, r7, r4
	mov r1, sp
	ldrh r1, [r1, #0x20]
	strh r1, [r0]
_0820048A:
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _0820051A
	bl VM_GetPC
	cmp r0, #0
	beq _082004B8
	bl Script_GetValue
	adds r1, r0, #0
	b _082004BA
	.align 2, 0
_082004A4: .4byte 0x000007E2
_082004A8: .4byte 0x000007E4
_082004AC: .4byte 0x000007E6
_082004B0: .4byte 0x000007EC
_082004B4: .4byte 0x000007EE
_082004B8:
	movs r1, #0
_082004BA:
	ldr r2, _082004D4 @ =0x000007F2
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r4, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _082004D8
	bl Script_GetValue
	subs r1, r4, r0
	b _082004DA
	.align 2, 0
_082004D4: .4byte 0x000007F2
_082004D8:
	adds r1, r4, #0
_082004DA:
	ldr r4, _082004F0 @ =0x000007F4
	adds r0, r7, r4
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _082004F4
	bl Script_GetValue
	adds r1, r0, #0
	b _082004F6
	.align 2, 0
_082004F0: .4byte 0x000007F4
_082004F4:
	movs r1, #0
_082004F6:
	ldr r2, _0820050C @ =0x000007F6
	adds r0, r7, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08200510
	bl Script_GetValue
	adds r1, r0, #0
	b _08200512
	.align 2, 0
_0820050C: .4byte 0x000007F6
_08200510:
	movs r1, #0
_08200512:
	movs r4, #0xff
	lsls r4, r4, #3
	adds r0, r7, r4
	b _08200538
_0820051A:
	ldr r0, _082005B0 @ =0x000007F2
	adds r1, r7, r0
	movs r0, #0x46
	strh r0, [r1]
	ldr r2, _082005B4 @ =0x000007F4
	adds r1, r7, r2
	movs r0, #0x32
	strh r0, [r1]
	ldr r4, _082005B8 @ =0x000007F6
	adds r0, r7, r4
	movs r1, #0x96
	lsls r1, r1, #1
	strh r1, [r0]
	adds r2, #4
	adds r0, r7, r2
_08200538:
	strh r1, [r0]
	mov r4, sb
	str r4, [sp]
	adds r0, r6, #0
	ldr r1, [sp, #0x1c]
	mov r2, sl
	add r3, sp, #0x14
	bl FUN_08022a70
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r6, r1
	strb r4, [r0]
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r4, r6, #0
	adds r4, #0xab
	strb r0, [r4]
	ldr r1, _082005BC @ =FUN_081ff988
	adds r0, r6, #0
	adds r0, #0xfc
	str r1, [r0]
	ldr r1, _082005C0 @ =FUN_081ff740
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r6, r2
	str r1, [r0]
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r5, #0
	mov r3, r8
	bl FUN_08022b2c
	adds r0, r7, #0
	mov r1, r8
	bl FUN_081ff8b0
	adds r0, r7, #0
	bl FUN_081ff7fc
	movs r0, #0x63
	bl prepare_08231510
	str r4, [sp, #0x2c]
	cmp r0, #0
	beq _082005C4
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r2, r0, #0
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08022fac
	b _082005CE
	.align 2, 0
_082005B0: .4byte 0x000007F2
_082005B4: .4byte 0x000007F4
_082005B8: .4byte 0x000007F6
_082005BC: .4byte FUN_081ff988
_082005C0: .4byte FUN_081ff740
_082005C4:
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08022fac
_082005CE:
	movs r0, #0x41
	bl prepare_08231510
	adds r4, r6, #0
	adds r4, #0x98
	str r4, [sp, #0x28]
	cmp r0, #0
	beq _082005FE
	movs r4, #0
	b _082005F2
_082005E2:
	bl Script_GetValue
	lsls r2, r4, #2
	adds r1, r6, #0
	adds r1, #0xe8
	adds r1, r1, r2
	str r0, [r1]
	adds r4, #1
_082005F2:
	cmp r4, #3
	bgt _082005FE
	bl VM_GetPC
	cmp r0, #0
	bne _082005E2
_082005FE:
	movs r0, #0x4b
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r5, _0820062C @ =0x00000844
	adds r1, r7, r5
	str r0, [r1]
	movs r0, #0x6a
	bl prepare_08231510
	cmp r0, #0
	beq _08200638
	bl Script_GetValue
	ldr r2, _08200630 @ =0x000007FA
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r4, _08200634 @ =0x000007FE
	adds r1, r7, r4
	b _08200646
	.align 2, 0
_0820062C: .4byte 0x00000844
_08200630: .4byte 0x000007FA
_08200634: .4byte 0x000007FE
_08200638:
	ldr r5, _082006F0 @ =0x000007FA
	adds r1, r7, r5
	movs r0, #0x1e
	strh r0, [r1]
	ldr r0, _082006F4 @ =0x000007FE
	adds r1, r7, r0
	movs r0, #5
_08200646:
	strh r0, [r1]
	ldr r1, _082006F0 @ =0x000007FA
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r2, _082006F8 @ =0x000007FC
	adds r0, r7, r2
	movs r4, #0
	mov sl, r4
	strh r1, [r0]
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r4, r7, r5
	movs r0, #0x87
	lsls r0, r0, #2
	adds r0, r0, r7
	mov sb, r0
	movs r1, #2
	str r1, [sp]
	movs r2, #0
	str r2, [sp, #4]
	movs r5, #0x3c
	str r5, [sp, #8]
	add r0, sp, #0x14
	str r0, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sb
	movs r3, #0
	bl FUN_0822f3fc
	movs r1, #1
	mov r8, r1
	str r1, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	adds r1, r4, #0
	mov r2, sb
	movs r3, #1
	bl FUN_08022da8
	ldr r0, [r4, #8]
	mov r2, r8
	orrs r0, r2
	str r0, [r4, #8]
	movs r1, #0x10
	ldr r4, [sp, #0x28]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r0, #0xdf
	lsls r0, r0, #2
	adds r5, r7, r0
	ldr r1, _082006FC @ =0x00002E7B
	adds r0, r5, #0
	bl FUN_0822b16c
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r4, r7, r1
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0822a470
	movs r2, #2
	strh r2, [r4, #0x10]
	ldr r0, [r4]
	movs r5, #0x11
	orrs r0, r5
	str r0, [r4]
	ldr r1, _08200700 @ =0x0000039F
	adds r0, r7, r1
	mov r2, sl
	strb r2, [r0]
	ldr r0, _08200704 @ =0x0000CB05
	ldr r1, _08200708 @ =0x0000DE23
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	bne _0820070C
_082006E8:
	movs r0, #1
	rsbs r0, r0, #0
	b _082009DA
	.align 2, 0
_082006F0: .4byte 0x000007FA
_082006F4: .4byte 0x000007FE
_082006F8: .4byte 0x000007FC
_082006FC: .4byte 0x00002E7B
_08200700: .4byte 0x0000039F
_08200704: .4byte 0x0000CB05
_08200708: .4byte 0x0000DE23
_0820070C:
	movs r4, #0xbf
	lsls r4, r4, #2
	adds r4, r7, r4
	str r4, [sp, #0x30]
	adds r1, r4, #0
	adds r0, r3, #0
	ldm r0!, {r2, r4, r5}
	stm r1!, {r2, r4, r5}
	ldm r0!, {r2, r4, r5}
	stm r1!, {r2, r4, r5}
	ldm r0!, {r2, r5}
	stm r1!, {r2, r5}
	ldr r0, [sp, #0x30]
	adds r1, r3, #0
	bl OpenSpriteSetFile
	movs r5, #0xc7
	lsls r5, r5, #2
	adds r4, r7, r5
	movs r0, #2
	str r0, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r2, #0x3c
	str r2, [sp, #8]
	add r5, sp, #0x14
	str r5, [sp, #0xc]
	adds r0, r4, #0
	ldr r1, [sp, #0x30]
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	ldr r0, [r4, #8]
	movs r1, #0x11
	orrs r0, r1
	str r0, [r4, #8]
	movs r2, #0xa7
	lsls r2, r2, #2
	adds r4, r7, r2
	movs r5, #2
	str r5, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r2, sp, #0x14
	str r2, [sp, #0xc]
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	str r5, [sp]
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0xf
	movs r3, #0
	bl FUN_082370cc
	ldr r0, [r4, #8]
	mov r5, r8
	orrs r0, r5
	str r0, [r4, #8]
	ldr r0, [sp, #0x2c]
	ldrb r4, [r0]
	cmp r4, #0
	beq _0820081C
	movs r0, #0x44
	movs r1, #0
	bl Script_GetKeywordValue
	adds r3, r0, #0
	cmp r3, #0
	beq _082007AA
	cmp r3, #1
	beq _082007E4
	b _0820084E
_082007AA:
	adds r0, r6, #0
	adds r0, #0xa4
	mov r1, r8
	strb r1, [r0]
	adds r0, #1
	mov r2, sl
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r3, [r0]
	subs r0, #0x14
	strb r1, [r0]
	ldr r1, _082007E0 @ =FUN_081febb8
	movs r0, #0xb
	adds r2, r6, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r0, #0x1d
	mov r4, r8
	strb r4, [r0]
	b _0820084E
	.align 2, 0
_082007E0: .4byte FUN_081febb8
_082007E4:
	adds r0, r6, #0
	adds r0, #0xa4
	mov r5, r8
	strb r5, [r0]
	adds r0, #1
	mov r1, sl
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	movs r2, #0
	str r2, [r0]
	subs r0, #0x14
	strb r5, [r0]
	ldr r1, _08200818 @ =FUN_081febb8
	movs r0, #0xb
	adds r2, r6, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	movs r4, #0
	b _08200848
	.align 2, 0
_08200818: .4byte FUN_081febb8
_0820081C:
	adds r0, r6, #0
	adds r0, #0xa4
	mov r5, r8
	strb r5, [r0]
	adds r0, #1
	mov r1, sl
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r4, [r0]
	subs r0, #0x14
	strb r5, [r0]
	ldr r1, _082008C4 @ =FUN_081febb8
	movs r0, #0xb
	adds r2, r6, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
_08200848:
	str r4, [r0]
	adds r0, #0x1d
	strb r5, [r0]
_0820084E:
	ldr r0, _082008C8 @ =0x03003584
	ldr r0, [r0]
	movs r2, #0x99
	lsls r2, r2, #6
	adds r2, r2, r0
	mov r8, r2
	movs r4, #0xa1
	lsls r4, r4, #2
	adds r4, r4, r7
	mov sb, r4
	adds r6, #0x48
	mov sl, r6
	movs r5, #0xf2
	lsls r5, r5, #2
	adds r4, r7, r5
	movs r5, #0xf
_0820086E:
	mov r0, r8
	adds r1, r4, #0
	ldr r2, _082008CC @ =0x04000008
	bl CpuSet
	adds r4, #0x20
	subs r5, #1
	cmp r5, #0
	bge _0820086E
	adds r0, r7, #0
	bl FUN_081fa620
	ldr r1, _082008C8 @ =0x03003584
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r5, r1, r0
	movs r0, #0xb9
	lsls r0, r0, #3
	adds r4, r7, r0
	movs r6, #0xf
_08200896:
	adds r0, r5, #0
	adds r1, r4, #0
	ldr r2, _082008CC @ =0x04000008
	bl CpuSet
	adds r5, #0x20
	adds r4, #0x20
	subs r6, #1
	cmp r6, #0
	bge _08200896
	adds r0, r7, #0
	bl FUN_081fa620
	adds r1, r0, #0
	cmp r1, #0
	bne _082008D0
	movs r1, #0xf2
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r2, sb
	str r0, [r2]
	b _082008DC
	.align 2, 0
_082008C4: .4byte FUN_081febb8
_082008C8: .4byte 0x03003584
_082008CC: .4byte 0x04000008
_082008D0:
	ldr r0, _082009EC @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	mov r4, sb
	str r0, [r4]
_082008DC:
	movs r1, #0x10
	ldr r5, [sp, #0x28]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	movs r1, #0xf9
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r4, _082009F0 @ =0x000007C9
	adds r0, r7, r4
	strb r2, [r0]
	ldr r5, _082009F4 @ =0x000007CA
	adds r1, r7, r5
	movs r3, #0
	ldr r0, _082009F8 @ =0x00000231
	strh r0, [r1]
	movs r1, #0xac
	lsls r1, r1, #1
	adds r0, r7, r1
	strb r3, [r0]
	adds r4, #0xf
	adds r0, r7, r4
	strh r2, [r0]
	adds r5, #0x10
	adds r0, r7, r5
	strh r2, [r0]
	ldr r1, _082009FC @ =0x00000804
	adds r0, r7, r1
	strh r2, [r0]
	adds r4, #0x2a
	adds r0, r7, r4
	strh r2, [r0]
	adds r5, #0x26
	adds r0, r7, r5
	strh r2, [r0]
	subs r1, #0x28
	adds r0, r7, r1
	strh r2, [r0]
	subs r4, #0x24
	adds r0, r7, r4
	strb r3, [r0]
	adds r5, #6
	adds r0, r7, r5
	strb r3, [r0]
	adds r1, #0x2b
	adds r0, r7, r1
	strb r3, [r0]
	adds r4, #0x2a
	adds r1, r7, r4
	str r2, [sp, #0x10]
	add r0, sp, #0x10
	ldr r2, _08200A00 @ =0x05000002
	bl CpuSet
	movs r2, #0
	adds r5, #0xa
	adds r0, r7, r5
	movs r1, #7
_08200954:
	strb r2, [r0]
	strb r2, [r0, #8]
	adds r0, #1
	subs r1, #1
	cmp r1, #0
	bge _08200954
	movs r4, #0
	movs r5, #0
_08200964:
	lsls r1, r4, #3
	adds r1, r1, r7
	movs r0, #0x82
	lsls r0, r0, #4
	adds r1, r1, r0
	str r5, [sp, #0x10]
	add r0, sp, #0x10
	ldr r2, _08200A00 @ =0x05000002
	bl CpuSet
	adds r4, #1
	cmp r4, #2
	ble _08200964
	movs r1, #0xc8
	lsls r1, r1, #2
	movs r4, #0xc8
	movs r2, #0xfa
	lsls r2, r2, #2
	movs r5, #0
	add r0, sp, #0x14
	strh r1, [r0]
	mov r1, sp
	strh r4, [r1, #0x16]
	strh r2, [r1, #0x18]
	strh r5, [r1, #0x1a]
	ldr r1, [sp, #0x24]
	ldr r2, [sp, #0x20]
	bl FUN_08202cd8
	ldr r2, _08200A04 @ =0x0000083C
	adds r1, r7, r2
	str r0, [r1]
	ldr r0, _08200A08 @ =0x00000514
	ldr r1, _08200A0C @ =0x000009C4
	mov r2, sp
	strh r0, [r2, #0x14]
	strh r4, [r2, #0x16]
	strh r1, [r2, #0x18]
	strh r5, [r2, #0x1a]
	add r0, sp, #0x14
	ldr r1, [sp, #0x24]
	ldr r2, [sp, #0x20]
	bl FUN_08202cd8
	movs r4, #0x84
	lsls r4, r4, #4
	adds r1, r7, r4
	str r0, [r1]
	mov r0, sl
	bl FUN_082047f0
	ldr r5, _08200A10 @ =0x000007CC
	adds r1, r7, r5
	str r0, [r1]
	movs r0, #0
	movs r1, #0
	bl FUN_081ea120
	movs r0, #0
_082009DA:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_082009EC: .4byte 0x03003584
_082009F0: .4byte 0x000007C9
_082009F4: .4byte 0x000007CA
_082009F8: .4byte 0x00000231
_082009FC: .4byte 0x00000804
_08200A00: .4byte 0x05000002
_08200A04: .4byte 0x0000083C
_08200A08: .4byte 0x00000514
_08200A0C: .4byte 0x000009C4
_08200A10: .4byte 0x000007CC

	thumb_func_start Dvalinn_Create
Dvalinn_Create: @ 0x08200A14
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #3
	bl FUN_08022a2c
	adds r4, r0, #0
	cmp r4, #0
	bne _08200A62
	ldr r1, _08200A50 @ =0x00000848
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08200A5C
	ldr r1, _08200A54 @ =Dvalinn_Update
	ldr r2, _08200A58 @ =Dvalinn_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Dvalinn_Init
	cmp r0, #0
	bge _08200A5C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08200A62
	.align 2, 0
_08200A50: .4byte 0x00000848
_08200A54: .4byte Dvalinn_Update
_08200A58: .4byte Dvalinn_Destroy
_08200A5C:
	ldr r0, _08200A68 @ =0x03002C80
	str r4, [r0]
	adds r0, r4, #0
_08200A62:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08200A68: .4byte 0x03002C80

	thumb_func_start FUN_08200a6c
FUN_08200a6c: @ 0x08200A6C
	push {r4, lr}
	ldr r0, _08200AAC @ =0x03002C80
	ldr r0, [r0]
	mov ip, r0
	movs r4, #3
	adds r0, #0xa2
	movs r1, #0
	strb r4, [r0]
	adds r0, #2
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	movs r3, #1
	strb r3, [r0]
	ldr r2, _08200AB0 @ =FUN_081fcf54
	subs r0, #5
	strb r4, [r0]
	adds r0, #0x55
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r0, #0x1d
	strb r3, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08200AAC: .4byte 0x03002C80
_08200AB0: .4byte FUN_081fcf54

