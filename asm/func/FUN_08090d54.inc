	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _08090D74 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x95
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #6
	ble _08090D78
	ldr r0, [r7, #0x24]
	b _08090D7A
	.align 2, 0
_08090D74: .4byte 0x030046A0
_08090D78:
	ldr r0, [r7, #0x20]
_08090D7A:
	str r0, [r7, #0x28]
	adds r0, r7, #0
	bl FUN_08090a00
	ldr r3, _08090DB0 @ =0x00004050
	adds r0, r7, r3
	ldrh r0, [r0]
	ldr r1, _08090DB4 @ =0x00004038
	adds r2, r7, r1
	strb r0, [r2]
	subs r3, #0x24
	adds r0, r7, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _08090DBC
	ldrb r0, [r2]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	bl FUN_0808fd2c
	cmp r0, #0
	beq _08090DBC
	ldr r0, _08090DB8 @ =0x00004039
	adds r1, r7, r0
	movs r0, #1
	b _08090DC2
	.align 2, 0
_08090DB0: .4byte 0x00004050
_08090DB4: .4byte 0x00004038
_08090DB8: .4byte 0x00004039
_08090DBC:
	ldr r2, _08090E7C @ =0x00004039
	adds r1, r7, r2
	movs r0, #0
_08090DC2:
	strb r0, [r1]
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r2, [r7, #0x28]
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r3, sp, #0xc
	str r3, [sp, #8]
	movs r0, #6
	movs r1, #2
	movs r3, #0
	bl FUN_0822c0b8
	ldr r1, _08090E7C @ =0x00004039
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08090E9C
	adds r0, r7, #0
	bl FUN_0808ff84
	ldr r2, _08090E80 @ =0x00004052
	adds r1, r7, r2
	ldr r3, _08090E84 @ =0x0000404C
	adds r3, r3, r7
	mov r8, r3
	ldrh r0, [r3]
	ldrh r1, [r1]
	adds r0, r0, r1
	subs r0, #0x78
	ldr r1, _08090E88 @ =0x00004040
	adds r5, r7, r1
	strh r0, [r5]
	adds r2, #2
	adds r1, r7, r2
	ldr r3, _08090E8C @ =0x0000404E
	adds r6, r7, r3
	ldrh r0, [r6]
	ldrh r1, [r1]
	adds r0, r0, r1
	subs r0, #0x50
	ldr r1, _08090E90 @ =0x00004042
	adds r4, r7, r1
	strh r0, [r4]
	adds r0, r7, #0
	bl FUN_08090040
	adds r0, r7, #0
	bl FUN_08090b38
	ldr r1, [r7, #0x28]
	ldr r2, _08090E94 @ =0x00004038
	adds r0, r7, r2
	ldrb r0, [r0]
	ldr r3, _08090E98 @ =0x0000402C
	adds r2, r7, r3
	ldr r2, [r2]
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r2, [r0, #1]
	movs r0, #1
	bl FUN_0822c398
	movs r0, #0
	ldrsh r3, [r5, r0]
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	subs r3, r3, r0
	movs r0, #0
	ldrsh r1, [r4, r0]
	movs r2, #0
	ldrsh r0, [r6, r2]
	subs r1, r1, r0
	asrs r5, r3, #3
	asrs r4, r1, #3
	movs r0, #2
	rsbs r0, r0, #0
	ands r4, r0
	str r1, [sp]
	movs r0, #1
	adds r1, r5, #0
	adds r2, r4, #0
	bl Video_GenerateBGMap
	adds r0, r7, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0808fe7c
	b _08090EA8
	.align 2, 0
_08090E7C: .4byte 0x00004039
_08090E80: .4byte 0x00004052
_08090E84: .4byte 0x0000404C
_08090E88: .4byte 0x00004040
_08090E8C: .4byte 0x0000404E
_08090E90: .4byte 0x00004042
_08090E94: .4byte 0x00004038
_08090E98: .4byte 0x0000402C
_08090E9C:
	adds r0, r7, #0
	bl FUN_08090698
	adds r0, r7, #0
	bl FUN_08090ca4
_08090EA8:
	ldr r0, [r7, #0x50]
	bl FUN_080478f0
	ldr r0, _08090ED8 @ =0x0000EFDA
	bl FUN_08047dc0
	movs r0, #1
	bl FUN_080477e4
	adds r0, r7, #0
	bl FUN_0808fbf4
	ldr r1, _08090EDC @ =FUN_080907f0
	adds r0, r7, #0
	movs r2, #0
	bl FUN_0808a354
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08090ED8: .4byte 0x0000EFDA
_08090EDC: .4byte FUN_080907f0
