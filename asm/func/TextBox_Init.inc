	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r0, _080485AC @ =0x030000C4
	str r6, [r0]
	adds r5, r6, #0
	adds r5, #0x18
	bl nop_0822ec58
	bl FUN_0822ec5c
	movs r0, #0x72
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080485B8
	bl Script_GetValue
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	bl Script_GetValue
	ldr r3, _080485B0 @ =0x00000179
	adds r1, r6, r3
	strb r0, [r1]
	bl Script_GetValue
	movs r7, #0xbd
	lsls r7, r7, #1
	adds r1, r6, r7
	strb r0, [r1]
	bl Script_GetValue
	ldr r2, _080485B4 @ =0x0000017B
	adds r1, r6, r2
	strb r0, [r1]
	b _080485D4
	.align 2, 0
_080485AC: .4byte 0x030000C4
_080485B0: .4byte 0x00000179
_080485B4: .4byte 0x0000017B
_080485B8:
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r6, r3
	strb r1, [r0]
	ldr r7, _0804864C @ =0x00000179
	adds r0, r6, r7
	strb r1, [r0]
	movs r2, #0xbd
	lsls r2, r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	adds r3, #3
	adds r0, r6, r3
	strb r1, [r0]
_080485D4:
	movs r7, #0xc6
	lsls r7, r7, #1
	adds r0, r6, r7
	movs r4, #0
	str r4, [r0]
	movs r0, #0x6c
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r1, r6, r2
	str r0, [r1]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r1, [r0]
	subs r7, #0x13
	adds r0, r6, r7
	ldrb r2, [r0]
	adds r3, #2
	adds r0, r6, r3
	ldrb r3, [r0]
	adds r7, #2
	adds r0, r6, r7
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r5, #0
	bl TextRenderer_Init
	movs r1, #0xbf
	lsls r1, r1, #1
	adds r0, r6, r1
	strb r4, [r0]
	movs r0, #0x73
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _08048650
	bl FUN_0823d340
	adds r1, r0, #0
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r0, r6, r2
	str r1, [r0]
	cmp r1, #0
	bne _08048638
	b _0804880C
_08048638:
	adds r0, r1, #0
	bl VM_ParseStringRef
	bl Textbox_LookupString
	str r0, [r5, #0x1c]
	cmp r0, #0
	bne _0804865A
	b _0804880C
	.align 2, 0
_0804864C: .4byte 0x00000179
_08048650:
	movs r3, #0xd0
	lsls r3, r3, #1
	adds r0, r6, r3
	str r1, [r0]
	str r1, [r5, #0x1c]
_0804865A:
	ldr r1, _080486C0 @ =0x0000519C
	movs r0, #0x63
	bl VM_GetKeywordValue
	adds r1, r0, #0
	adds r0, r6, #0
	bl TextBox_LoadBgPltt
	cmp r0, #0
	bge _08048670
	b _0804880C
_08048670:
	adds r0, r6, #0
	bl TextBox_UploadBgPltt
	movs r4, #0
	strb r4, [r5, #0x11]
	ldr r7, _080486C4 @ =0x00000181
	adds r0, r6, r7
	strb r4, [r0]
	movs r0, #0x69
	movs r1, #0
	bl VM_GetKeywordValue
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r7, #0
	strh r0, [r1]
	ldr r3, _080486C8 @ =0x00000183
	adds r1, r6, r3
	movs r0, #3
	strb r0, [r1]
	ldr r1, _080486CC @ =0x0000017F
	adds r0, r6, r1
	strb r7, [r0]
	adds r2, #6
	adds r0, r6, r2
	strb r7, [r0]
	adds r3, #1
	adds r0, r6, r3
	strh r4, [r0]
	strb r7, [r5, #0xd]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080486F0
	movs r7, #0xbb
	lsls r7, r7, #2
	adds r4, r6, r7
	b _080486E6
	.align 2, 0
_080486C0: .4byte 0x0000519C
_080486C4: .4byte 0x00000181
_080486C8: .4byte 0x00000183
_080486CC: .4byte 0x0000017F
_080486D0:
	bl Script_GetValue
	ldrb r2, [r5, #0xd]
	lsls r2, r2, #2
	adds r1, r5, #0
	adds r1, #0xc4
	adds r1, r1, r2
	str r0, [r1]
	ldrb r0, [r5, #0xd]
	adds r0, #1
	strb r0, [r5, #0xd]
_080486E6:
	bl VM_GetPC
	cmp r0, #0
	bne _080486D0
	b _080486F8
_080486F0:
	strb r7, [r5, #0xd]
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r4, r6, r0
_080486F8:
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r0, _080487EC @ =0x0000FFFF
	strh r0, [r1]
	ldr r1, _080487F0 @ =TextBox_StateIdle
	str r1, [r4]
	movs r3, #0xbf
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r0, [r0]
	ldr r5, _080487F4 @ =0x0000CB05
	mov sl, r5
	ldr r1, _080487F8 @ =0x000082F1
	mov r0, sl
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _0804880C
	movs r7, #0xf6
	lsls r7, r7, #1
	adds r4, r6, r7
	adds r1, r4, #0
	adds r0, r2, #0
	ldm r0!, {r3, r5, r7}
	stm r1!, {r3, r5, r7}
	ldm r0!, {r3, r5, r7}
	stm r1!, {r3, r5, r7}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r2, _080487FC @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0xdf
	orrs r0, r1
	ldr r1, _080487EC @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x8f
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x10]
	add r7, sp, #0x10
	mov r8, r7
	ldr r0, [sp, #0x14]
	ands r0, r2
	str r0, [sp, #0x14]
	movs r0, #0x83
	lsls r0, r0, #2
	adds r5, r6, r0
	ldr r3, _08048800 @ =0x00003071
	movs r1, #0
	str r1, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r2, #0x3c
	mov sb, r2
	str r2, [sp, #8]
	add r7, sp, #0x10
	str r7, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #8
	bl MainSprite_Add
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r1, _08048804 @ =0x0000D27A
	mov r0, sl
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _0804880C
	movs r1, #0x9b
	lsls r1, r1, #2
	adds r4, r6, r1
	adds r1, r4, #0
	ldm r0!, {r3, r5, r7}
	stm r1!, {r3, r5, r7}
	ldm r0!, {r3, r5, r7}
	stm r1!, {r3, r5, r7}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	movs r1, #4
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x40
	mov r7, r8
	strh r0, [r7, #2]
	movs r0, #0
	strh r0, [r7, #4]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r3, _08048808 @ =0x00001051
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	mov r5, sb
	str r5, [sp, #8]
	add r7, sp, #0x10
	str r7, [sp, #0xc]
	adds r1, r4, #0
	bl MainSprite_Add
	movs r0, #0
	b _08048810
	.align 2, 0
_080487EC: .4byte 0x0000FFFF
_080487F0: .4byte TextBox_StateIdle
_080487F4: .4byte 0x0000CB05
_080487F8: .4byte 0x000082F1
_080487FC: .4byte 0xFFFF0000
_08048800: .4byte 0x00003071
_08048804: .4byte 0x0000D27A
_08048808: .4byte 0x00001051
_0804880C:
	movs r0, #1
	rsbs r0, r0, #0
_08048810:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
