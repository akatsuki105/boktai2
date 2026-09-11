	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	adds r7, r0, #0
	mov r8, r1
	mov sb, r7
	movs r0, #0x74
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [sp, #0x28]
	adds r0, r7, #0
	ldr r1, [sp, #0x28]
	bl FUN_08022a0c
	movs r0, #0x53
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0x82
	lsls r2, r2, #4
	adds r1, r7, r2
	str r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r3, _08035F3C @ =0x00000824
	adds r1, r7, r3
	str r0, [r1]
	movs r0, #0x50
	movs r1, #2
	bl VM_GetKeywordValue
	ldr r4, _08035F40 @ =0x0000016B
	adds r1, r7, r4
	strb r0, [r1]
	movs r4, #0
	cmp r4, r0
	bge _08035F58
	adds r3, r1, #0
	movs r5, #0x82
	lsls r5, r5, #1
	adds r1, r7, r5
	ldr r2, _08035F44 @ =0x03002BE0
_08035F30:
	ldr r0, [r2]
	cmp r0, #0
	beq _08035F48
	str r0, [r1]
	adds r0, #0x2c
	b _08035F4A
	.align 2, 0
_08035F3C: .4byte 0x00000824
_08035F40: .4byte 0x0000016B
_08035F44: .4byte 0x03002BE0
_08035F48:
	str r0, [r1]
_08035F4A:
	str r0, [r1, #8]
	adds r1, #4
	adds r2, #4
	adds r4, #1
	ldrb r6, [r3]
	cmp r4, r6
	blt _08035F30
_08035F58:
	ldr r0, _08035FCC @ =0x0000CB05
	ldr r1, _08035FD0 @ =0x0000D3DA
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	bne _08035F6A
	bl _08036760
_08035F6A:
	movs r1, #0xb5
	lsls r1, r1, #2
	adds r0, r7, r1
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r4, r5, r6}
	stm r2!, {r4, r5, r6}
	ldm r1!, {r4, r5, r6}
	stm r2!, {r4, r5, r6}
	ldm r1!, {r4, r5}
	stm r2!, {r4, r5}
	adds r1, r3, #0
	bl OpenSpriteSetFile
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08035FDC
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08035FD4 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08035FD8 @ =0x0000FFFF
	ldr r1, [sp, #0x1c]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x1c]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x20]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x20]
	bl Script_GetValue
	adds r5, r0, #0
	b _08036004
	.align 2, 0
_08035FCC: .4byte 0x0000CB05
_08035FD0: .4byte 0x0000D3DA
_08035FD4: .4byte 0xFFFF0000
_08035FD8: .4byte 0x0000FFFF
_08035FDC:
	ldr r0, _08036070 @ =0x030046A0
	ldr r3, [r0]
	ldrh r0, [r3, #0x30]
	ldr r4, _08036074 @ =0xFFFF0000
	ldr r1, [sp, #0x1c]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x1c]
	ldrh r2, [r3, #0x32]
	lsls r2, r2, #0x10
	ldr r0, _08036078 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x1c]
	ldrh r1, [r3, #0x34]
	ldr r0, [sp, #0x20]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x20]
	movs r5, #0x40
_08036004:
	ldr r0, [sp, #0x1c]
	asrs r0, r0, #0x10
	movs r6, #0xb2
	lsls r6, r6, #1
	adds r1, r7, r6
	strh r0, [r1]
	ldr r0, _0803607C @ =0x00000868
	adds r4, r7, r0
	adds r0, r4, #0
	bl FUN_08084734
	ldr r1, _08036080 @ =0x00000844
	adds r2, r7, r1
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r7, #0
	bl FUN_08028604
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08036094
	bl Script_GetValue
	mov sl, r0
	bl Script_GetValue
	movs r2, #0x8a
	lsls r2, r2, #4
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _08036084 @ =0x000008A2
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	ldr r4, _08036088 @ =0x000008A4
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	ldr r6, _0803608C @ =0x000008D2
	adds r1, r7, r6
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _08036090 @ =0x000008D6
	adds r1, r7, r2
	b _080360C4
	.align 2, 0
_08036070: .4byte 0x030046A0
_08036074: .4byte 0xFFFF0000
_08036078: .4byte 0x0000FFFF
_0803607C: .4byte 0x00000868
_08036080: .4byte 0x00000844
_08036084: .4byte 0x000008A2
_08036088: .4byte 0x000008A4
_0803608C: .4byte 0x000008D2
_08036090: .4byte 0x000008D6
_08036094:
	movs r3, #0xfa
	lsls r3, r3, #2
	mov sl, r3
	movs r4, #0x8a
	lsls r4, r4, #4
	adds r1, r7, r4
	ldr r0, _08036154 @ =0x000003E7
	strh r0, [r1]
	ldr r6, _08036158 @ =0x000008A2
	adds r1, r7, r6
	movs r0, #0xa
	strh r0, [r1]
	ldr r0, _0803615C @ =0x000008A4
	adds r1, r7, r0
	movs r0, #0x64
	strh r0, [r1]
	ldr r2, _08036160 @ =0x000008D2
	adds r1, r7, r2
	adds r0, #0xc8
	strh r0, [r1]
	ldr r3, _08036164 @ =0x000008D6
	adds r1, r7, r3
	movs r0, #0x96
	lsls r0, r0, #2
_080360C4:
	strh r0, [r1]
	ldr r4, _08036168 @ =0x000008DB
	adds r2, r7, r4
	movs r0, #0x60
	strb r0, [r2]
	ldr r6, _0803616C @ =0x000008DC
	adds r1, r7, r6
	movs r0, #0x30
	strb r0, [r1]
	ldrb r0, [r2]
	movs r2, #0xbf
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08036180
	bl Script_GetValue
	ldr r3, _08036170 @ =0x000008A8
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	subs r4, #0x31
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	subs r6, #0x30
	adds r1, r7, r6
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _08036174 @ =0x000008AE
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r3, #0x8b
	lsls r3, r3, #4
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	adds r4, #8
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	adds r6, #0x18
	adds r1, r7, r6
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _08036178 @ =0x000008C6
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _0803617C @ =0x000008C8
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	adds r4, #0x18
	adds r1, r7, r4
	strh r0, [r1]
	b _080361C8
	.align 2, 0
_08036154: .4byte 0x000003E7
_08036158: .4byte 0x000008A2
_0803615C: .4byte 0x000008A4
_08036160: .4byte 0x000008D2
_08036164: .4byte 0x000008D6
_08036168: .4byte 0x000008DB
_0803616C: .4byte 0x000008DC
_08036170: .4byte 0x000008A8
_08036174: .4byte 0x000008AE
_08036178: .4byte 0x000008C6
_0803617C: .4byte 0x000008C8
_08036180:
	ldr r6, _080361F0 @ =0x000008A8
	adds r1, r7, r6
	movs r0, #0x19
	strh r0, [r1]
	ldr r1, _080361F4 @ =0x000008AA
	adds r0, r7, r1
	movs r2, #0x32
	strh r2, [r0]
	ldr r3, _080361F8 @ =0x000008AC
	adds r0, r7, r3
	movs r1, #0x3c
	strh r1, [r0]
	ldr r4, _080361FC @ =0x000008AE
	adds r0, r7, r4
	strh r2, [r0]
	adds r6, #8
	adds r0, r7, r6
	strh r2, [r0]
	adds r3, #6
	adds r0, r7, r3
	strh r1, [r0]
	adds r4, #0x16
	adds r1, r7, r4
	movs r0, #8
	strh r0, [r1]
	adds r6, #0x16
	adds r1, r7, r6
	movs r0, #0x10
	strh r0, [r1]
	ldr r0, _08036200 @ =0x000008C8
	adds r1, r7, r0
	movs r0, #0xa
	strh r0, [r1]
	ldr r1, _08036204 @ =0x000008CA
	adds r0, r7, r1
	strh r2, [r0]
_080361C8:
	movs r0, #0x67
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08036214
	bl Script_GetValue
	ldr r2, _08036208 @ =0x000008B4
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _0803620C @ =0x000008B6
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	ldr r4, _08036210 @ =0x000008B8
	adds r1, r7, r4
	b _0803622A
	.align 2, 0
_080361F0: .4byte 0x000008A8
_080361F4: .4byte 0x000008AA
_080361F8: .4byte 0x000008AC
_080361FC: .4byte 0x000008AE
_08036200: .4byte 0x000008C8
_08036204: .4byte 0x000008CA
_08036208: .4byte 0x000008B4
_0803620C: .4byte 0x000008B6
_08036210: .4byte 0x000008B8
_08036214:
	ldr r6, _08036260 @ =0x000008B4
	adds r1, r7, r6
	movs r0, #0x46
	strh r0, [r1]
	ldr r0, _08036264 @ =0x000008B6
	adds r1, r7, r0
	movs r0, #0x50
	strh r0, [r1]
	ldr r2, _08036268 @ =0x000008B8
	adds r1, r7, r2
	movs r0, #0x41
_0803622A:
	strh r0, [r1]
	movs r0, #0x55
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08036278
	bl Script_GetValue
	ldr r3, _0803626C @ =0x000008BA
	adds r1, r7, r3
	strh r0, [r1]
	bl Script_GetValue
	ldr r4, _08036270 @ =0x000008BC
	adds r1, r7, r4
	strh r0, [r1]
	bl Script_GetValue
	ldr r6, _08036274 @ =0x000008BE
	adds r1, r7, r6
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0x8c
	lsls r2, r2, #4
	adds r1, r7, r2
	b _08036298
	.align 2, 0
_08036260: .4byte 0x000008B4
_08036264: .4byte 0x000008B6
_08036268: .4byte 0x000008B8
_0803626C: .4byte 0x000008BA
_08036270: .4byte 0x000008BC
_08036274: .4byte 0x000008BE
_08036278:
	ldr r3, _080362E8 @ =0x000008BA
	adds r1, r7, r3
	movs r0, #0x28
	strh r0, [r1]
	ldr r4, _080362EC @ =0x000008BC
	adds r1, r7, r4
	movs r0, #0x50
	strh r0, [r1]
	ldr r6, _080362F0 @ =0x000008BE
	adds r1, r7, r6
	movs r0, #0x32
	strh r0, [r1]
	movs r0, #0x8c
	lsls r0, r0, #4
	adds r1, r7, r0
	movs r0, #0x1e
_08036298:
	strh r0, [r1]
	ldr r2, _080362F4 @ =0x000008CE
	adds r1, r7, r2
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r1]
	movs r3, #0x8d
	lsls r3, r3, #4
	adds r1, r7, r3
	movs r0, #0x80
	lsls r0, r0, #3
	strh r0, [r1]
	str r5, [sp]
	mov r0, sb
	mov r1, r8
	ldr r2, [sp, #0x28]
	add r3, sp, #0x1c
	bl Boss_Init_08022a70
	movs r0, #0x8a
	lsls r0, r0, #1
	add r0, sb
	strb r5, [r0]
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	mov r1, sb
	adds r1, #0xab
	strb r0, [r1]
	ldrb r0, [r1]
	str r1, [sp, #0x24]
	cmp r0, #0
	beq _080362F8
	movs r4, #0xb0
	lsls r4, r4, #1
	adds r1, r7, r4
	movs r0, #0
	b _08036300
	.align 2, 0
_080362E8: .4byte 0x000008BA
_080362EC: .4byte 0x000008BC
_080362F0: .4byte 0x000008BE
_080362F4: .4byte 0x000008CE
_080362F8:
	movs r5, #0xb0
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0x40
_08036300:
	strh r0, [r1]
	movs r6, #0xbd
	lsls r6, r6, #2
	adds r6, r6, r7
	mov r8, r6
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r5, r7, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #0
	str r4, [sp, #4]
	movs r6, #0x3c
	str r6, [sp, #8]
	add r1, sp, #0x1c
	str r1, [sp, #0xc]
	mov r0, r8
	adds r1, r5, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	movs r2, #0xd5
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r1, #3
	str r1, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r3, sp, #0x1c
	str r3, [sp, #0xc]
	adds r1, r5, #0
	movs r2, #0
	movs r3, #1
	bl FUN_0822f3fc
	movs r0, #1
	str r0, [sp]
	str r4, [sp, #4]
	mov r0, sb
	mov r1, r8
	adds r2, r5, #0
	movs r3, #0
	bl FUN_08022da8
	adds r0, r7, #0
	bl FUN_08027ed0
	adds r1, r0, #0
	cmp r1, #0
	bne _08036374
	movs r4, #0xcf
	lsls r4, r4, #2
	adds r1, r7, r4
	movs r5, #0x84
	lsls r5, r5, #3
	adds r0, r7, r5
	b _08036382
_08036374:
	ldr r0, _080363BC @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r6, #0xcf
	lsls r6, r6, #2
	adds r1, r7, r6
_08036382:
	str r0, [r1]
	adds r0, r1, #0
	movs r2, #0xe7
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r7, #0
	bl FUN_0802a208
	adds r0, r7, #0
	bl FUN_08029ab8
	ldr r4, [sp, #0x24]
	ldrb r3, [r4]
	cmp r3, #0
	beq _08036474
	movs r0, #0x44
	movs r1, #1
	bl VM_GetKeywordValue
	adds r4, r0, #0
	cmp r4, #1
	beq _08036400
	cmp r4, #1
	bgt _080363C0
	cmp r4, #0
	beq _080363C6
	b _080364A8
	.align 2, 0
_080363BC: .4byte 0x03003584
_080363C0:
	cmp r4, #2
	beq _08036438
	b _080364A8
_080363C6:
	movs r1, #2
	mov r0, sb
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #0x16
	str r4, [r0]
	subs r0, #0x14
	movs r2, #1
	strb r2, [r0]
	ldr r1, _080363FC @ =FUN_0803331c
	movs r0, #0x23
	mov r3, sb
	adds r3, #0xa3
	strb r0, [r3]
	mov r0, sb
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r4, [r0]
	adds r0, #0x1d
	strb r2, [r0]
	b _080364A8
	.align 2, 0
_080363FC: .4byte FUN_0803331c
_08036400:
	movs r1, #2
	movs r2, #0
	mov r0, sb
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r4, [r0]
	adds r0, #0x16
	str r2, [r0]
	subs r0, #0x14
	strb r4, [r0]
	ldr r1, _08036434 @ =FUN_080333a4
	movs r0, #0x24
	mov r3, sb
	adds r3, #0xa3
	strb r0, [r3]
	mov r0, sb
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r2, [r0]
	adds r0, #0x1d
	strb r4, [r0]
	b _080364A8
	.align 2, 0
_08036434: .4byte FUN_080333a4
_08036438:
	movs r1, #0
	movs r2, #0x10
	mov r0, sb
	adds r0, #0xa4
	strb r4, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	movs r3, #1
	strb r3, [r0]
	ldr r2, _08036470 @ =FUN_080333a4
	movs r0, #0x34
	mov r4, sb
	adds r4, #0xa3
	strb r0, [r4]
	mov r0, sb
	adds r0, #0xf8
	str r2, [r0]
	subs r0, #0x6c
	str r1, [r0]
	adds r0, #0x1d
	strb r3, [r0]
	b _080364A8
	.align 2, 0
_08036470: .4byte FUN_080333a4
_08036474:
	movs r2, #0x78
	adds r0, r7, #0
	adds r0, #0xa4
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #1
	strb r3, [r0]
	adds r0, #0x16
	str r3, [r0]
	subs r0, #0x14
	movs r1, #1
	strb r1, [r0]
	ldr r5, _0803650C @ =0x0000089C
	adds r0, r7, r5
	strh r2, [r0]
	ldr r2, _08036510 @ =FUN_0802e520
	mov r0, sb
	adds r0, #0xa3
	strb r1, [r0]
	adds r0, #0x55
	str r2, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r0, #0x1d
	strb r1, [r0]
_080364A8:
	ldr r1, _08036514 @ =PreDurathrorEvent_08035aa8
	mov r0, sb
	adds r0, #0xfc
	str r1, [r0]
	ldr r1, _08036518 @ =FUN_08035a64
	movs r0, #0x80
	lsls r0, r0, #1
	add r0, sb
	str r1, [r0]
	movs r6, #0x8a
	lsls r6, r6, #4
	adds r4, r7, r6
	ldrh r3, [r4]
	mov r0, sb
	mov r1, sl
	mov r2, sl
	bl FUN_08022b2c
	adds r0, r7, #0
	bl FUN_0802ab3c
	ldrh r1, [r4]
	adds r0, r7, #0
	bl FUN_0802ac94
	adds r0, r7, #0
	bl FUN_0802abe8
	adds r0, r7, #0
	bl FUN_0802ad28
	movs r0, #0x64
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _08036520
	bl Script_GetValue
	movs r2, #0x82
	lsls r2, r2, #5
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r3, _0803651C @ =0x00001042
	adds r1, r7, r3
	strh r0, [r1]
	b _0803652E
	.align 2, 0
_0803650C: .4byte 0x0000089C
_08036510: .4byte FUN_0802e520
_08036514: .4byte PreDurathrorEvent_08035aa8
_08036518: .4byte FUN_08035a64
_0803651C: .4byte 0x00001042
_08036520:
	movs r4, #0x82
	lsls r4, r4, #5
	adds r0, r7, r4
	strh r1, [r0]
	ldr r5, _08036550 @ =0x00001042
	adds r0, r7, r5
	strh r1, [r0]
_0803652E:
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08036554
	bl Script_GetValue
	adds r4, r0, #0
	bl Script_GetValue
	adds r2, r0, #0
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08022fac
	b _0803655E
	.align 2, 0
_08036550: .4byte 0x00001042
_08036554:
	mov r0, sb
	movs r1, #0
	movs r2, #0
	bl FUN_08022fac
_0803655E:
	movs r0, #0x41
	bl VM_SeekToKeyword
	mov r6, sb
	adds r6, #0xde
	movs r1, #0x48
	add r1, sb
	mov r8, r1
	cmp r0, #0
	beq _08036592
	movs r4, #0
	b _08036586
_08036576:
	bl Script_GetValue
	lsls r2, r4, #2
	mov r1, sb
	adds r1, #0xe8
	adds r1, r1, r2
	str r0, [r1]
	adds r4, #1
_08036586:
	cmp r4, #3
	bgt _08036592
	bl VM_GetPC
	cmp r0, #0
	bne _08036576
_08036592:
	ldr r2, _080366BC @ =0x000008C2
	adds r1, r7, r2
	movs r5, #0
	movs r0, #0xfa
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x4b
	movs r1, #0
	bl VM_GetKeywordValue
	movs r3, #0x8e
	lsls r3, r3, #4
	adds r1, r7, r3
	str r0, [r1]
	movs r0, #0x78
	movs r1, #2
	bl VM_GetKeywordValue
	strb r0, [r6]
	ldr r4, _080366C0 @ =0x00000173
	adds r1, r7, r4
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_0802adb8
	movs r6, #0xed
	lsls r6, r6, #2
	adds r4, r7, r6
	movs r0, #0xc5
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #0x40
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0xc8
	lsls r0, r0, #5
	str r0, [sp, #8]
	movs r2, #1
	str r2, [sp, #0xc]
	movs r0, #6
	str r0, [sp, #0x10]
	str r2, [sp, #0x14]
	str r5, [sp, #0x18]
	adds r0, r4, #0
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_08013ba8
	ldr r1, _080366C4 @ =0x00001C1B
	adds r0, r4, #0
	movs r2, #7
	bl FUN_08013c94
	ldr r0, _080366C8 @ =0x03003584
	ldr r0, [r0]
	movs r1, #0x99
	lsls r1, r1, #6
	adds r6, r0, r1
	movs r2, #0x84
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r4, #0xf
_08036610:
	adds r0, r6, #0
	adds r1, r5, #0
	ldr r2, _080366CC @ =0x04000008
	bl CpuSet
	adds r5, #0x20
	subs r4, #1
	cmp r4, #0
	bge _08036610
	ldr r0, _080366C8 @ =0x03003584
	ldr r0, [r0]
	movs r3, #0xc3
	lsls r3, r3, #5
	adds r6, r0, r3
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r5, r7, r4
	movs r4, #1
_08036634:
	adds r0, r6, #0
	adds r1, r5, #0
	ldr r2, _080366CC @ =0x04000008
	bl CpuSet
	adds r5, #0x20
	subs r4, #1
	cmp r4, #0
	bge _08036634
	movs r0, #0xcc
	lsls r0, r0, #3
	adds r5, r7, r0
	movs r4, #0xd
_0803664E:
	adds r0, r6, #0
	adds r1, r5, #0
	ldr r2, _080366CC @ =0x04000008
	bl CpuSet
	adds r6, #0x20
	adds r5, #0x20
	subs r4, #1
	cmp r4, #0
	bge _0803664E
	movs r2, #0xc5
	lsls r2, r2, #2
	adds r1, r7, r2
	adds r0, r7, #0
	bl FUN_08028790
	adds r0, r7, #0
	bl FUN_08028dbc
	adds r0, r7, #0
	bl FUN_08029d1c
	ldr r3, _080366D0 @ =0x0000087C
	adds r1, r7, r3
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_08027ed0
	ldr r4, _080366D4 @ =0x0000087A
	adds r1, r7, r4
	movs r2, #0
	strh r0, [r1]
	movs r0, #0xc8
	lsls r0, r0, #1
	mov r5, r8
	strh r2, [r5, #0x30]
	strh r0, [r5, #0x32]
	strh r2, [r5, #0x34]
	ldr r6, [sp, #0x24]
	ldrb r0, [r6]
	cmp r0, #0
	beq _080366E4
	ldr r1, _080366D8 @ =0x0000104C
	adds r0, r7, r1
	str r2, [r0]
	ldr r3, _080366DC @ =0x00001050
	adds r0, r7, r3
	str r2, [r0]
	ldr r4, _080366E0 @ =0x00001058
	adds r0, r7, r4
	str r2, [r0]
	b _08036728
	.align 2, 0
_080366BC: .4byte 0x000008C2
_080366C0: .4byte 0x00000173
_080366C4: .4byte 0x00001C1B
_080366C8: .4byte 0x03003584
_080366CC: .4byte 0x04000008
_080366D0: .4byte 0x0000087C
_080366D4: .4byte 0x0000087A
_080366D8: .4byte 0x0000104C
_080366DC: .4byte 0x00001050
_080366E0: .4byte 0x00001058
_080366E4:
	ldr r5, _08036744 @ =0x000008BA
	adds r0, r7, r5
	ldrh r0, [r0]
	bl FUN_0805a31c
	ldr r6, _08036748 @ =0x0000104C
	adds r1, r7, r6
	str r0, [r1]
	cmp r0, #0
	beq _08036760
	ldr r1, _0803674C @ =0x000008BC
	adds r0, r7, r1
	ldrh r0, [r0]
	movs r2, #0x8c
	lsls r2, r2, #4
	adds r1, r7, r2
	ldrh r1, [r1]
	bl FUN_0805b068
	ldr r3, _08036750 @ =0x00001050
	adds r1, r7, r3
	str r0, [r1]
	cmp r0, #0
	beq _08036760
	ldr r4, _08036754 @ =0x0000016B
	adds r0, r7, r4
	ldrb r0, [r0]
	bl FUN_0805d364
	ldr r5, _08036758 @ =0x00001058
	adds r1, r7, r5
	str r0, [r1]
	cmp r0, #0
	beq _08036760
_08036728:
	movs r6, #0x82
	lsls r6, r6, #4
	adds r0, r7, r6
	ldr r0, [r0]
	bl FUN_0805b790
	ldr r2, _0803675C @ =0x00001054
	adds r1, r7, r2
	str r0, [r1]
	cmp r0, #0
	beq _08036760
	movs r0, #0
	b _08036764
	.align 2, 0
_08036744: .4byte 0x000008BA
_08036748: .4byte 0x0000104C
_0803674C: .4byte 0x000008BC
_08036750: .4byte 0x00001050
_08036754: .4byte 0x0000016B
_08036758: .4byte 0x00001058
_0803675C: .4byte 0x00001054
_08036760:
	movs r0, #1
	rsbs r0, r0, #0
_08036764:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
