	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x80
	mov sb, r0
	add r5, sp, #0x28
	adds r1, r5, #0
	ldr r0, _08218F00 @ =0x08252814
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	add r4, sp, #0x34
	ldr r1, _08218F04 @ =0x08252820
	adds r0, r4, #0
	movs r2, #0x24
	bl memcpy
	ldr r0, _08218F08 @ =0x000012C8
	add r0, sb
	mov r8, r0
	movs r0, #0
	bl FUN_0822b644
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r7, _08218F0C @ =0x030046A0
	ldr r0, [r7]
	ldr r1, _08218F10 @ =0x0000093A
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _08218EE0
	b _082191DE
_08218EE0:
	add r6, sp, #0x58
	ldr r1, _08218F14 @ =0x08252844
	adds r0, r6, #0
	movs r2, #0xa
	bl memcpy
	ldr r0, [r7]
	movs r3, #0x94
	lsls r3, r3, #2
	adds r0, r0, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #5
	bne _08218F18
	adds r4, r6, #0
	b _08218F1E
	.align 2, 0
_08218F00: .4byte 0x08252814
_08218F04: .4byte 0x08252820
_08218F08: .4byte 0x000012C8
_08218F0C: .4byte 0x030046A0
_08218F10: .4byte 0x0000093A
_08218F14: .4byte 0x08252844
_08218F18:
	bl FUN_0823cd38
	adds r4, r0, #0
_08218F1E:
	movs r0, #8
	movs r1, #7
	movs r2, #0xc
	movs r3, #2
	bl FUN_0821b28c
	movs r0, #8
	movs r1, #7
	adds r2, r4, #0
	bl Video_DrawText
	ldr r0, _08218F50 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _08218F54
	cmp r0, #5
	beq _08218F58
	movs r6, #2
	b _08218F5A
	.align 2, 0
_08218F50: .4byte 0x030046A0
_08218F54:
	movs r6, #0
	b _08218F5A
_08218F58:
	movs r6, #1
_08218F5A:
	mov r0, r8
	adds r0, #0x20
	lsls r1, r6, #2
	adds r1, r5, r1
	ldrh r2, [r1]
	mov r1, r8
	movs r3, #1
	bl Sprite_SetSprite
	mov r3, r8
	ldr r0, [r3, #0x28]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0x28]
	movs r5, #0
	lsls r0, r6, #1
	add r7, sp, #0x64
	mov r4, sp
	adds r4, #0xa
	str r4, [sp, #0x6c]
	adds r3, #0xe0
	str r3, [sp, #0x7c]
	movs r1, #0xa0
	lsls r1, r1, #1
	add r1, r8
	str r1, [sp, #0x68]
	movs r2, #0x18
	add sb, r2
	movs r3, #0x98
	lsls r3, r3, #2
	add r3, r8
	str r3, [sp, #0x74]
	movs r4, #0x80
	lsls r4, r4, #2
	add r4, r8
	mov sl, r4
	movs r1, #0xd0
	lsls r1, r1, #1
	add r1, r8
	str r1, [sp, #0x78]
	movs r2, #0xc8
	lsls r2, r2, #2
	add r2, r8
	str r2, [sp, #0x70]
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r4, r0, #0
	add r4, sp
	adds r4, #0x34
_08218FBE:
	adds r1, r5, #0
	adds r1, #8
	ldrb r3, [r4]
	movs r6, #0
	str r6, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r2, #6
	bl FUN_0822bcf4
	adds r4, #1
	adds r5, #1
	cmp r5, #0xb
	ble _08218FBE
	movs r0, #3
	movs r1, #0xa
	movs r2, #0x18
	movs r3, #2
	bl FUN_0821b28c
	str r6, [sp, #0x64]
	ldr r2, _0821901C @ =0x05000008
	adds r0, r7, #0
	add r1, sp, #8
	bl CpuSet
	movs r0, #0xe4
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r4, r0, #0
	bl FUN_0808fc14
	adds r4, r4, r0
	adds r0, r4, #0
	bl Textbox_LookupString
	adds r4, r0, #0
	add r1, sp, #8
	movs r0, #0x80
	strb r0, [r1]
	movs r0, #0xb9
	strb r0, [r1, #1]
	ldr r1, [sp, #0x6c]
	b _08219026
	.align 2, 0
_0821901C: .4byte 0x05000008
_08219020:
	strb r0, [r1]
	adds r4, #1
	adds r1, #1
_08219026:
	ldrb r0, [r4]
	cmp r0, #0
	bne _08219020
	movs r0, #0x80
	strb r0, [r1]
	movs r0, #0xba
	strb r0, [r1, #1]
	movs r0, #3
	movs r1, #0xa
	add r2, sp, #8
	bl Video_DrawText
	ldr r3, _08219154 @ =0x030046A0
	ldr r0, [r3]
	movs r4, #0x90
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _0821905E
	mov r0, r8
	adds r0, #0x88
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_0821905E:
	ldr r6, [sp, #0x7c]
	ldr r2, _08219154 @ =0x030046A0
	ldr r0, [r2]
	movs r4, #0xad
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r1, _08219158 @ =0x00034BC0
	bl Div
	adds r5, r0, #0
	ldr r3, _08219154 @ =0x030046A0
	ldr r0, [r3]
	adds r0, r0, r4
	ldr r0, [r0]
	movs r1, #0xe1
	lsls r1, r1, #4
	bl Div
	lsls r1, r5, #4
	subs r1, r1, r5
	lsls r1, r1, #2
	subs r7, r0, r1
	cmp r5, #0x63
	ble _08219094
	movs r5, #0x63
	movs r7, #0x3b
_08219094:
	adds r0, r5, #0
	movs r1, #0xa
	bl Mod
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r0, [sp, #0x68]
	mov r1, sb
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r5, #0
	movs r1, #0xa
	bl Div
	adds r5, r0, #0
	movs r1, #0xa
	bl Mod
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sb
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, [r6, #8]
	movs r4, #2
	rsbs r4, r4, #0
	ands r0, r4
	str r0, [r6, #8]
	ldr r0, [r6, #0x68]
	ands r0, r4
	str r0, [r6, #0x68]
	adds r0, r7, #0
	movs r1, #0xa
	bl Mod
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r0, [sp, #0x74]
	mov r1, sb
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r7, #0
	movs r1, #0xa
	bl Div
	adds r7, r0, #0
	movs r1, #0xa
	bl Mod
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r0, sl
	mov r1, sb
	movs r3, #1
	bl Sprite_SetSprite
	mov r1, sl
	ldr r0, [r1, #8]
	ands r0, r4
	str r0, [r1, #8]
	ldr r2, [sp, #0x74]
	ldr r0, [r2, #8]
	ands r0, r4
	str r0, [r2, #8]
	ldr r3, [sp, #0x78]
	ldr r0, [r3, #8]
	ands r0, r4
	str r0, [r3, #8]
	ldr r4, _08219154 @ =0x030046A0
	ldr r1, [r4]
	movs r2, #0x94
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #5
	bne _0821915C
	adds r0, r1, #0
	adds r0, #0x40
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r4, r0, #0
	adds r4, #0xa
	cmp r4, #0x63
	ble _08219164
	movs r4, #0x63
	b _08219164
	.align 2, 0
_08219154: .4byte 0x030046A0
_08219158: .4byte 0x00034BC0
_0821915C:
	adds r0, r1, #0
	adds r0, #0x40
	movs r1, #0
	ldrsh r4, [r0, r1]
_08219164:
	movs r6, #0xb0
	lsls r6, r6, #2
	add r6, r8
	adds r0, r4, #0
	movs r1, #0xa
	bl Mod
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r0, [sp, #0x70]
	mov r1, sb
	movs r3, #1
	bl Sprite_SetSprite
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	adds r4, r0, #0
	movs r1, #0xa
	bl Mod
	adds r2, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sb
	movs r3, #1
	bl Sprite_SetSprite
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	ldr r0, [r6, #0x68]
	ands r0, r1
	str r0, [r6, #0x68]
	movs r0, #0xe2
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #3
	bl Textbox_LookupString
	adds r4, r0, #0
	movs r0, #0x15
	movs r1, #7
	movs r2, #3
	movs r3, #2
	bl FUN_0821b28c
	movs r0, #0x15
	movs r1, #7
	adds r2, r4, #0
	bl Video_DrawText
	b _08219226
_082191DE:
	movs r5, #0
	movs r6, #0
	movs r4, #2
_082191E4:
	adds r1, r5, #0
	adds r1, #8
	str r6, [sp]
	str r4, [sp, #4]
	movs r0, #2
	movs r2, #6
	movs r3, #1
	bl FUN_0822bcf4
	adds r5, #1
	cmp r5, #8
	ble _082191E4
	movs r0, #0xe2
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #2
	bl Textbox_LookupString
	adds r4, r0, #0
	movs r0, #8
	movs r1, #6
	movs r2, #0x12
	movs r3, #2
	bl FUN_0821b28c
	movs r0, #8
	movs r1, #6
	adds r2, r4, #0
	bl Video_DrawText
_08219226:
	add sp, #0x80
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
