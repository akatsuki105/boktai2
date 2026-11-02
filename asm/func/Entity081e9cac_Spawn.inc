	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp, #8]
	mov r8, r1
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r0, _081E9998 @ =0x030001B4
	ldr r0, [r0]
	cmp r0, #0
	bne _081E999C
	bl Entity081e9cac_Create
	mov sb, r0
	cmp r0, #0
	bne _081E999E
_081E9992:
	movs r0, #0
	b _081E9B7C
	.align 2, 0
_081E9998: .4byte 0x030001B4
_081E999C:
	mov sb, r0
_081E999E:
	mov r0, sb
	bl Entity081e9cac_AllocElem
	adds r6, r0, #0
	cmp r6, #0
	beq _081E9992
	adds r7, r6, #0
	adds r7, #0x64
	adds r5, r6, #0
	adds r5, #0x90
	mov r4, sb
	adds r4, #0x1c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r0, [r6, #0x64]
	movs r1, #1
	mov sl, r1
	orrs r0, r1
	str r0, [r6, #0x64]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	adds r1, r6, #0
	adds r1, #0xec
	movs r0, #0
	strh r0, [r1]
	ldr r2, [sp, #8]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	mov r0, r8
	cmp r0, #0
	beq _081E9A0C
	ldrh r0, [r0]
	ldrh r1, [r7, #0x1c]
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	mov r2, r8
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #0x1e]
	adds r0, r0, r1
	strh r0, [r7, #0x1e]
	ldrh r0, [r2, #4]
	ldrh r2, [r7, #0x20]
	adds r0, r0, r2
	strh r0, [r7, #0x20]
_081E9A0C:
	ldr r2, [sp, #0xc]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0xc]
	str r1, [r6, #0x10]
	movs r0, #0xff
	strb r0, [r6, #1]
	mov r0, sp
	ldrb r0, [r0, #0x10]
	strb r0, [r6, #2]
	adds r1, r6, #0
	adds r1, #0xea
	ldr r0, [sp, #0x34]
	strh r0, [r1]
	adds r1, #6
	ldr r0, [sp, #0x44]
	strh r0, [r1]
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r6, #4]
	str r1, [r6, #8]
	adds r2, r6, #0
	adds r2, #0xac
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r5]
	mov r1, sl
	orrs r0, r1
	str r0, [r5]
	ldrb r0, [r6, #2]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl Entity081e9cac_GetAnimVariant
	adds r5, r6, #0
	adds r5, #0xbc
	mov r2, sb
	ldr r1, [r2, #0x18]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r4]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #2
	bl AuxAnim_SetAnim
	adds r0, r6, #0
	adds r0, #0xcc
	mov r2, sb
	ldr r1, [r2, #0x18]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #0
	bl AuxAnim_RestartAnim
	mov r8, r7
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r5, #4]
	mov r1, sl
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sl
	ands r0, r2
	cmp r1, r0
	beq _081E9AB4
	ldr r0, [r6, #0x64]
	movs r1, #4
	orrs r0, r1
	b _081E9ABC
_081E9AB4:
	ldr r0, [r6, #0x64]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081E9ABC:
	str r0, [r6, #0x64]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081E9AE2
	mov r1, r8
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081E9AEC
_081E9AE2:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081E9AEC:
	mov r2, r8
	str r0, [r2]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _081E9B24 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _081E9B5C
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081E9B28
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _081E9B1E
	ldrb r0, [r5, #5]
_081E9B1E:
	subs r0, #1
	strh r0, [r5, #8]
	b _081E9B38
	.align 2, 0
_081E9B24: .4byte 0x0000FFFF
_081E9B28:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _081E9B38
	strh r1, [r5, #8]
_081E9B38:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E9B5C
	movs r0, #1
	strb r0, [r5, #7]
_081E9B5C:
	adds r0, r6, #0
	ldr r1, [sp, #0x38]
	ldr r2, [sp, #0x3c]
	ldr r3, [sp, #0x40]
	bl Entity081e9cacElem_InitHitbox
	adds r0, r6, #0
	bl Entity081e9cacElem_UpdateHitPos
	movs r0, #1
	strb r0, [r6]
	strb r0, [r7, #7]
	adds r1, r6, #0
	adds r1, #0x97
	strb r0, [r1]
	adds r0, r6, #0
_081E9B7C:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
