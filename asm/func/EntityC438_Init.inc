	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	mov r8, r0
	ldr r0, _080AAE2C @ =0x0000CB05
	ldr r1, _080AAE30 @ =0x000082F1
	bl GetFile
	adds r1, r0, #0
	add r2, sp, #0x10
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	add r0, sp, #0x10
	bl OpenSpriteSetFile
	movs r0, #0x70
	bl VM_SeekToKeyword
	adds r3, r0, #0
	cmp r3, #0
	beq _080AAE34
	bl Script_GetValue
	mov r5, r8
	adds r5, #0x7c
	strh r0, [r5]
	bl Script_GetValue
	mov r4, r8
	adds r4, #0x7e
	strh r0, [r4]
	bl Script_GetValue
	mov r1, r8
	adds r1, #0x80
	strh r0, [r1]
	mov sl, r5
	str r4, [sp, #0x38]
	str r1, [sp, #0x3c]
	b _080AAE4C
	.align 2, 0
_080AAE2C: .4byte 0x0000CB05
_080AAE30: .4byte 0x000082F1
_080AAE34:
	mov r2, r8
	adds r2, #0x7c
	strh r3, [r2]
	mov r1, r8
	adds r1, #0x7e
	strh r3, [r1]
	mov r0, r8
	adds r0, #0x80
	strh r3, [r0]
	mov sl, r2
	str r1, [sp, #0x38]
	str r0, [sp, #0x3c]
_080AAE4C:
	movs r0, #0x6f
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080AAE8C
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _080AAE84 @ =0xFFFF0000
	adds r4, r5, #0
	ands r4, r6
	orrs r4, r0
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r1, _080AAE88 @ =0x0000FFFF
	ands r4, r1
	adds r6, r4, #0
	orrs r6, r0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r7
	adds r7, r5, #0
	orrs r7, r0
	b _080AAE92
	.align 2, 0
_080AAE84: .4byte 0xFFFF0000
_080AAE88: .4byte 0x0000FFFF
_080AAE8C:
	ldr r0, _080AAEA8 @ =0xFFFF0000
	movs r6, #0
	ands r7, r0
_080AAE92:
	movs r0, #0x49
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080AAEAC
	bl Script_GetValue
	mov r5, r8
	strh r0, [r5, #0x1a]
	b _080AAEB4
	.align 2, 0
_080AAEA8: .4byte 0xFFFF0000
_080AAEAC:
	movs r0, #0xc0
	lsls r0, r0, #1
	mov r1, r8
	strh r0, [r1, #0x1a]
_080AAEB4:
	movs r0, #0x74
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080AAEC8
	bl Script_GetValue
	mov r2, r8
	strh r0, [r2, #0x18]
	b _080AAECC
_080AAEC8:
	mov r3, r8
	strh r0, [r3, #0x18]
_080AAECC:
	movs r0, #0x52
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080AAEDE
	bl Script_GetValue
	mov sb, r0
	b _080AAEE2
_080AAEDE:
	movs r4, #1
	mov sb, r4
_080AAEE2:
	mov r5, r8
	ldrh r0, [r5, #0x18]
	cmp r0, #0
	beq _080AAEF2
	cmp r0, #1
	beq _080AAF08
	movs r5, #0
	b _080AAF1C
_080AAEF2:
	movs r0, #0x64
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080AAF02
	bl Script_GetValue
	b _080AAF04
_080AAF02:
	movs r0, #0
_080AAF04:
	adds r5, r0, #0
	b _080AAF1C
_080AAF08:
	movs r0, #0x64
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080AAF18
	bl Script_GetValue
	b _080AAF1A
_080AAF18:
	movs r0, #0
_080AAF1A:
	adds r5, r0, #4
_080AAF1C:
	adds r0, r6, #0
	mov r1, sl
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080AAF98 @ =0xFFFF0000
	ldr r2, [sp, #0x30]
	ands r2, r4
	orrs r2, r0
	str r2, [sp, #0x30]
	asrs r1, r6, #0x10
	ldr r3, [sp, #0x38]
	ldrh r3, [r3]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	ldr r0, _080AAF9C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x30]
	adds r1, r7, #0
	ldr r0, [sp, #0x3c]
	ldrh r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r3, sp, #0x30
	ldr r0, [r3, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r3, #4]
	mov r0, r8
	adds r0, #0x1c
	lsls r2, r5, #0x10
	lsrs r2, r2, #0x10
	mov r4, sb
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r3, [sp, #0xc]
	add r1, sp, #0x10
	movs r3, #0
	bl FUN_0822f3fc
	ldr r0, _080AAFA0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080AAFA4
	mov r5, r8
	ldr r0, [r5, #0x24]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x24]
	b _080AAFC8
	.align 2, 0
_080AAF98: .4byte 0xFFFF0000
_080AAF9C: .4byte 0x0000FFFF
_080AAFA0: .4byte 0x030047A4
_080AAFA4:
	mov r0, r8
	bl FUN_080aad30
	cmp r0, #0
	beq _080AAFBE
	mov r1, r8
	ldr r0, [r1, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
	str r0, [r2, #0x24]
	b _080AAFC8
_080AAFBE:
	mov r3, r8
	ldr r0, [r3, #0x24]
	movs r1, #1
	orrs r0, r1
	str r0, [r3, #0x24]
_080AAFC8:
	movs r0, #0
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
