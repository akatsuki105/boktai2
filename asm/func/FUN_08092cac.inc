	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	ldr r0, _08092DF4 @ =0x00003AEE
	adds r5, r6, r0
	ldrb r0, [r5]
	adds r0, #0x11
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r0, _08092DF8 @ =0x00000F6C
	adds r2, r6, r0
	adds r2, r2, r1
	ldr r0, [r2]
	movs r1, #1
	mov r8, r1
	orrs r0, r1
	str r0, [r2]
	add r4, sp, #0x10
	ldrb r1, [r5]
	adds r0, r4, #0
	bl FUN_080921e8
	add r0, sp, #0x10
	ldrh r0, [r0]
	adds r0, #8
	add r1, sp, #0x10
	strh r0, [r1]
	ldrh r0, [r4, #2]
	adds r0, #8
	strh r0, [r4, #2]
	ldr r2, _08092DFC @ =0x0203B400
	mov sl, r2
	ldr r4, _08092E00 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _08092E04 @ =0x000003FF
	mov sb, r1
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	movs r2, #6
	rsbs r2, r2, #0
	adds r1, r2, #0
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08092E08 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, [r4]
	adds r0, #1
	mov r1, sb
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	movs r2, #5
	rsbs r2, r2, #0
	adds r1, r2, #0
	subs r1, r1, r0
	lsls r1, r1, #0x10
	ldr r2, _08092E0C @ =0x0000FFFF
	ldr r0, [sp, #0x18]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r0, [r4]
	adds r0, #1
	mov r1, sb
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	adds r0, #5
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r0, [r4]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _08092D8A
	rsbs r0, r7, #0
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
_08092D8A:
	ldr r2, _08092E10 @ =0x00003F9C
	adds r0, r6, r2
	ldrb r0, [r0]
	ldrb r1, [r5]
	bl GetItemID
	adds r2, r0, #0
	adds r2, #0x68
	ldrb r1, [r5]
	adds r1, #0x11
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r6, r0
	ldr r1, _08092E14 @ =0x00000F9E
	adds r0, r0, r1
	ldrh r3, [r0]
	add r0, sp, #0x10
	str r0, [sp]
	add r0, sp, #0x18
	str r0, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	adds r0, r6, #0
	bl FUN_0808c334
	movs r2, #0xed
	lsls r2, r2, #6
	adds r0, r6, r2
	strh r7, [r0]
	bl TextBox_Close
	bl FUN_08049e5c
	bl FUN_08049f84
	ldr r0, _08092E18 @ =0x0000027D
	bl PlaySound_082406e0
	ldr r1, _08092E1C @ =FUN_0809312c
	adds r0, r6, #0
	movs r2, #1
	bl FUN_0808a354
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08092DF4: .4byte 0x00003AEE
_08092DF8: .4byte 0x00000F6C
_08092DFC: .4byte 0x0203B400
_08092E00: .4byte 0x030046B8
_08092E04: .4byte 0x000003FF
_08092E08: .4byte 0xFFFF0000
_08092E0C: .4byte 0x0000FFFF
_08092E10: .4byte 0x00003F9C
_08092E14: .4byte 0x00000F9E
_08092E18: .4byte 0x0000027D
_08092E1C: .4byte FUN_0809312c
