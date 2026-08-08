	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	mov r8, r1
	mov sb, r2
	ldr r0, _0807AF4C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	bne _0807AE8C
	b _0807AFCC
_0807AE8C:
	ldr r0, _0807AF50 @ =0x000004C7
	adds r4, r7, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0807AEB2
	ldr r1, _0807AF54 @ =0x000004C5
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, r8
	beq _0807AEAC
	cmp r0, #3
	bne _0807AEA6
	b _0807AFCC
_0807AEA6:
	adds r0, r7, #0
	bl FUN_08063248
_0807AEAC:
	ldrb r0, [r4]
	cmp r0, #0
	bne _0807AEC8
_0807AEB2:
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrb r1, [r0]
	adds r2, #1
	adds r0, r7, r2
	movs r2, #0
	strb r1, [r0]
	ldr r1, _0807AF58 @ =0x000003DA
	adds r0, r7, r1
	strh r2, [r0]
_0807AEC8:
	ldr r6, _0807AF5C @ =0x0203B400
	ldr r4, _0807AF60 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _0807AF64 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r2, #0xf
	ands r0, r2
	subs r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _0807AF68 @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r5
	orrs r2, r0
	str r2, [sp]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	movs r0, #0x1f
	ands r1, r0
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	ldr r0, _0807AF6C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r5
	str r0, [sp, #4]
	movs r5, #0
	cmp r5, sb
	bge _0807AF34
	mov r4, sb
_0807AF18:
	ldr r2, _0807AF70 @ =0x000004C4
	adds r0, r7, r2
	mov r1, r8
	movs r2, #0xe1
	lsls r2, r2, #4
	mov r3, sp
	bl FUN_082467d0
	cmp r0, #0
	blt _0807AF2E
	movs r5, #1
_0807AF2E:
	subs r4, #1
	cmp r4, #0
	bne _0807AF18
_0807AF34:
	cmp r5, #0
	beq _0807AFC4
	ldr r1, _0807AF54 @ =0x000004C5
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0807AF78
	ldr r0, _0807AF74 @ =0x00000191
	bl PlaySound_082406e0
	b _0807AFC4
	.align 2, 0
_0807AF4C: .4byte 0x030047A4
_0807AF50: .4byte 0x000004C7
_0807AF54: .4byte 0x000004C5
_0807AF58: .4byte 0x000003DA
_0807AF5C: .4byte 0x0203B400
_0807AF60: .4byte 0x030046B8
_0807AF64: .4byte 0x000003FF
_0807AF68: .4byte 0xFFFF0000
_0807AF6C: .4byte 0x0000FFFF
_0807AF70: .4byte 0x000004C4
_0807AF74: .4byte 0x00000191
_0807AF78:
	cmp r0, #2
	bne _0807AF98
	ldr r2, _0807AF90 @ =0x00000376
	adds r0, r7, r2
	ldrh r1, [r0]
	adds r1, #0xa
	strh r1, [r0]
	ldr r0, _0807AF94 @ =0x00000133
	bl PlaySound_082406e0
	b _0807AFC4
	.align 2, 0
_0807AF90: .4byte 0x00000376
_0807AF94: .4byte 0x00000133
_0807AF98:
	cmp r0, #3
	bne _0807AFC4
	ldr r0, _0807AFDC @ =0x00000133
	bl PlaySound_082406e0
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0xa
	strh r0, [r1]
	movs r2, #0xd8
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r0, [r1]
	cmp r0, #0
	bne _0807AFBC
	movs r0, #1
	strh r0, [r1]
_0807AFBC:
	ldr r0, _0807AFE0 @ =0x000003D2
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
_0807AFC4:
	ldr r2, _0807AFE4 @ =0x0000043E
	adds r1, r7, r2
	movs r0, #0
	strh r0, [r1]
_0807AFCC:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807AFDC: .4byte 0x00000133
_0807AFE0: .4byte 0x000003D2
_0807AFE4: .4byte 0x0000043E
