	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x68
	str r0, [sp, #0x2c]
	str r1, [sp, #0x30]
	str r2, [sp, #0x34]
	adds r4, r3, #0
	ldr r5, [sp, #0x88]
	movs r0, #0
	str r0, [sp, #0x54]
	ldr r0, [sp, #0x2c]
	bl FUN_080ae428
	mov r1, sp
	ldrh r2, [r1, #0x30]
	ldr r1, _080AE4E8 @ =0x03003F60
	strh r2, [r1, #0x10]
	mov r3, sp
	ldrh r3, [r3, #0x34]
	strh r3, [r1, #0x12]
	strh r4, [r1, #0x20]
	strh r5, [r1, #0x22]
	ldr r4, [r1, #0x2c]
	mov sb, r4
	movs r5, #0x18
	ldrsh r0, [r1, r5]
	lsls r0, r0, #1
	str r0, [sp, #0x3c]
	movs r2, #0x1a
	ldrsh r0, [r1, r2]
	lsls r0, r0, #1
	str r0, [sp, #0x40]
	add r4, sp, #0x24
	ldr r3, [sp, #0x2c]
	movs r5, #0xa0
	lsls r5, r5, #3
	adds r2, r3, r5
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r5, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r5, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r6, r4, #0
	cmp r0, #0
	blt _080AE4EC
	asrs r0, r0, #8
	b _080AE4F2
	.align 2, 0
_080AE4E8: .4byte 0x03003F60
_080AE4EC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080AE4F2:
	strh r0, [r4]
	adds r1, r5, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080AE504
	asrs r0, r0, #8
	b _080AE50A
_080AE504:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080AE50A:
	adds r3, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080AE51E
	asrs r1, r0, #8
	b _080AE524
_080AE51E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_080AE524:
	subs r0, r3, r1
	strh r0, [r4, #2]
	adds r0, r3, r1
	strh r0, [r4, #4]
	movs r2, #0
	ldrsh r1, [r6, r2]
	ldr r2, _080AE554 @ =0x03003540
	movs r3, #8
	ldrsh r0, [r2, r3]
	adds r1, r1, r0
	str r1, [sp, #0x4c]
	add r0, sp, #0x24
	movs r4, #2
	ldrsh r1, [r0, r4]
	movs r5, #0xa
	ldrsh r0, [r2, r5]
	adds r1, r1, r0
	str r1, [sp, #0x50]
	ldr r0, [sp, #0x4c]
	cmp r0, #0
	blt _080AE558
	asrs r0, r0, #3
	b _080AE560
	.align 2, 0
_080AE554: .4byte 0x03003540
_080AE558:
	ldr r1, [sp, #0x4c]
	rsbs r0, r1, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080AE560:
	str r0, [sp, #0x4c]
	ldr r2, [sp, #0x50]
	cmp r2, #0
	blt _080AE56C
	asrs r0, r2, #3
	b _080AE574
_080AE56C:
	ldr r3, [sp, #0x50]
	rsbs r0, r3, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080AE574:
	movs r4, #2
	rsbs r4, r4, #0
	ands r4, r0
	ldr r5, [sp, #0x4c]
	ldr r0, [sp, #0x30]
	subs r5, r5, r0
	str r5, [sp, #0x4c]
	ldr r1, [sp, #0x34]
	subs r4, r4, r1
	str r4, [sp, #0x50]
	ldr r2, [sp, #0x2c]
	ldr r3, _080AE5E0 @ =0x000004DC
	adds r0, r2, r3
	ldr r2, [r0]
	mov r1, sp
	adds r0, r2, #0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldr r0, [sp, #0xc]
	adds r0, r0, r2
	str r0, [sp, #0xc]
	str r0, [sp, #0x38]
	ldr r4, [sp, #0x2c]
	ldr r5, _080AE5E4 @ =0x0000132A
	adds r1, r4, r5
	movs r0, #0
	strb r0, [r1]
	movs r3, #0
	ldrb r0, [r4, #0x1e]
	cmp r3, r0
	blt _080AE5B8
	b _080AE882
_080AE5B8:
	mov r1, sp
	adds r1, #0x18
	str r1, [sp, #0x58]
_080AE5BE:
	ldr r2, [sp, #0x2c]
	movs r4, #0xc1
	lsls r4, r4, #4
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080AE5DA
	ldr r5, _080AE5E8 @ =0x000004FC
	adds r0, r2, r5
	ldrh r0, [r0]
	cmp r0, #0xa
	beq _080AE5EC
	cmp r0, #0xe
	beq _080AE5EC
_080AE5DA:
	movs r1, #5
	b _080AE604
	.align 2, 0
_080AE5E0: .4byte 0x000004DC
_080AE5E4: .4byte 0x0000132A
_080AE5E8: .4byte 0x000004FC
_080AE5EC:
	lsls r1, r3, #2
	ldr r2, [sp, #0x2c]
	ldr r4, _080AE63C @ =0x00000BE8
	adds r0, r2, r4
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, #0xcf
	ldrb r0, [r0]
	movs r1, #5
	cmp r0, #4
	bne _080AE604
	movs r1, #0
_080AE604:
	ldr r5, [sp, #0x2c]
	ldr r2, _080AE640 @ =0x000004E4
	adds r0, r5, r2
	adds r0, r0, r3
	strb r1, [r0]
	movs r4, #0x9d
	lsls r4, r4, #3
	adds r0, r5, r4
	adds r2, r0, r3
	ldrb r0, [r2]
	adds r5, r3, #1
	str r5, [sp, #0x60]
	cmp r0, r1
	bne _080AE622
	b _080AE876
_080AE622:
	cmp r1, #0
	bne _080AE62A
	movs r0, #1
	str r0, [sp, #0x54]
_080AE62A:
	strb r1, [r2]
	cmp r3, #1
	beq _080AE68E
	cmp r3, #1
	bgt _080AE644
	cmp r3, #0
	beq _080AE64E
	b _080AE6AC
	.align 2, 0
_080AE63C: .4byte 0x00000BE8
_080AE640: .4byte 0x000004E4
_080AE644:
	cmp r3, #2
	beq _080AE666
	cmp r3, #3
	beq _080AE67E
	b _080AE6AC
_080AE64E:
	ldr r2, [sp, #0x4c]
	mov ip, r2
	ldr r4, [sp, #0x50]
	mov r8, r4
	mov r7, ip
	subs r7, #7
	cmp r7, #0
	bge _080AE660
	movs r7, #0
_080AE660:
	mov r2, r8
	subs r2, #6
	b _080AE6A4
_080AE666:
	ldr r5, [sp, #0x4c]
	adds r5, #7
	mov ip, r5
	ldr r0, [sp, #0x50]
	mov r8, r0
	ldr r7, [sp, #0x4c]
	cmp r7, #0
	bge _080AE678
	movs r7, #0
_080AE678:
	mov r2, r8
	subs r2, #6
	b _080AE6A4
_080AE67E:
	ldr r2, [sp, #0x4c]
	mov ip, r2
	ldr r4, [sp, #0x50]
	adds r4, #4
	mov r8, r4
	mov r7, ip
	subs r7, #7
	b _080AE69C
_080AE68E:
	ldr r5, [sp, #0x4c]
	adds r5, #7
	mov ip, r5
	ldr r0, [sp, #0x50]
	adds r0, #4
	mov r8, r0
	ldr r7, [sp, #0x4c]
_080AE69C:
	cmp r7, #0
	bge _080AE6A2
	movs r7, #0
_080AE6A2:
	ldr r2, [sp, #0x50]
_080AE6A4:
	cmp r2, #0
	bge _080AE6B6
	movs r2, #0
	b _080AE6B6
_080AE6AC:
	movs r7, #1
	rsbs r7, r7, #0
	adds r2, r7, #0
	mov r8, r7
	mov ip, r8
_080AE6B6:
	adds r3, #1
	str r3, [sp, #0x60]
	mov r3, ip
	cmp r3, #0
	bge _080AE6C2
	b _080AE876
_080AE6C2:
	mov r4, r8
	cmp r4, #0
	bge _080AE6CA
	b _080AE876
_080AE6CA:
	cmp r7, #0x1f
	ble _080AE6D0
	b _080AE876
_080AE6D0:
	cmp r2, #0x1f
	ble _080AE6D6
	b _080AE876
_080AE6D6:
	ldr r5, _080AE72C @ =0x03003F60
	ldrh r0, [r5, #0x18]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	str r0, [sp, #0x48]
	cmp r1, #5
	bne _080AE730
	adds r6, r2, #0
	cmp r6, r8
	blt _080AE6EC
	b _080AE876
_080AE6EC:
	adds r5, r7, #0
	adds r0, r6, #2
	str r0, [sp, #0x5c]
	cmp r5, ip
	bge _080AE722
	movs r4, #0x1f
	movs r3, #0
_080AE6FA:
	ldr r1, [sp, #0x30]
	adds r2, r1, r5
	ldr r0, [sp, #0x34]
	adds r1, r0, r6
	ands r2, r4
	ands r1, r4
	lsls r0, r1, #5
	adds r0, r2, r0
	lsls r0, r0, #1
	add r0, sb
	strh r3, [r0]
	adds r1, #1
	lsls r1, r1, #5
	adds r2, r2, r1
	lsls r2, r2, #1
	add r2, sb
	strh r3, [r2]
	adds r5, #1
	cmp r5, ip
	blt _080AE6FA
_080AE722:
	ldr r6, [sp, #0x5c]
	cmp r6, r8
	blt _080AE6EC
	b _080AE876
	.align 2, 0
_080AE72C: .4byte 0x03003F60
_080AE730:
	adds r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [sp, #0x58]
	ldr r3, [sp, #0x38]
	adds r0, r0, r3
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldr r4, [sp, #0x2c]
	ldr r5, _080AE7AC @ =0x000004DC
	adds r0, r4, r5
	ldr r3, [sp, #0x58]
	ldr r1, [r3, #8]
	ldr r0, [r0]
	adds r1, r1, r0
	str r1, [r3, #8]
	ldr r4, _080AE7B0 @ =0x03003F60
	str r1, [r4, #0x28]
	str r1, [sp, #0x44]
	adds r6, r2, #0
	cmp r6, r8
	blt _080AE760
	b _080AE876
_080AE760:
	adds r5, r7, #0
	adds r0, r6, #2
	str r0, [sp, #0x5c]
	cmp r5, ip
	blt _080AE76C
	b _080AE86E
_080AE76C:
	movs r1, #0x1f
	mov sl, r1
_080AE770:
	ldr r2, [sp, #0x30]
	adds r4, r2, r5
	ldr r0, [sp, #0x34]
	adds r3, r0, r6
	cmp r4, #0
	blt _080AE78C
	cmp r3, #0
	blt _080AE78C
	ldr r1, [sp, #0x3c]
	cmp r4, r1
	bge _080AE78C
	ldr r2, [sp, #0x40]
	cmp r3, r2
	blt _080AE7B4
_080AE78C:
	mov r0, sl
	ands r4, r0
	ands r3, r0
	lsls r0, r3, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	strh r1, [r0]
	adds r0, r3, #1
	lsls r0, r0, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	add r0, sb
	b _080AE864
	.align 2, 0
_080AE7AC: .4byte 0x000004DC
_080AE7B0: .4byte 0x03003F60
_080AE7B4:
	cmp r4, #0
	blt _080AE7BC
	asrs r0, r4, #5
	b _080AE7C2
_080AE7BC:
	rsbs r0, r4, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_080AE7C2:
	adds r1, r0, #0
	cmp r3, #0
	blt _080AE7CC
	asrs r0, r3, #5
	b _080AE7D2
_080AE7CC:
	rsbs r0, r3, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_080AE7D2:
	ldr r2, [sp, #0x48]
	muls r0, r2, r0
	adds r0, r1, r0
	lsls r2, r0, #8
	mov r0, sl
	ands r4, r0
	ands r3, r0
	cmp r4, #0
	blt _080AE7E8
	asrs r0, r4, #1
	b _080AE7EE
_080AE7E8:
	rsbs r0, r4, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080AE7EE:
	adds r1, r0, #0
	cmp r3, #0
	blt _080AE7F8
	asrs r0, r3, #1
	b _080AE7FE
_080AE7F8:
	rsbs r0, r3, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080AE7FE:
	lsls r0, r0, #4
	adds r1, r2, r1
	adds r1, r1, r0
	lsls r1, r1, #1
	ldr r2, [sp, #0x44]
	adds r1, r1, r2
	ldrh r2, [r1]
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	bne _080AE840
	lsls r1, r3, #5
	adds r1, r4, r1
	lsls r1, r1, #1
	add r1, sb
	str r1, [sp, #0x64]
	ldr r1, _080AE83C @ =0x03003F60
	ldr r0, [r1, #0x24]
	lsls r2, r2, #3
	adds r2, r2, r0
	ldrh r0, [r2]
	ldr r1, [sp, #0x64]
	strh r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	add r0, sb
	ldrh r1, [r2, #4]
	b _080AE864
	.align 2, 0
_080AE83C: .4byte 0x03003F60
_080AE840:
	lsls r1, r3, #5
	adds r1, r4, r1
	lsls r1, r1, #1
	add r1, sb
	str r1, [sp, #0x64]
	ldr r1, _080AE8A0 @ =0x03003F60
	ldr r0, [r1, #0x24]
	lsls r2, r2, #3
	adds r2, r2, r0
	ldrh r0, [r2, #2]
	ldr r1, [sp, #0x64]
	strh r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #5
	adds r0, r4, r0
	lsls r0, r0, #1
	add r0, sb
	ldrh r1, [r2, #6]
_080AE864:
	strh r1, [r0]
	adds r5, #1
	cmp r5, ip
	bge _080AE86E
	b _080AE770
_080AE86E:
	ldr r6, [sp, #0x5c]
	cmp r6, r8
	bge _080AE876
	b _080AE760
_080AE876:
	ldr r3, [sp, #0x60]
	ldr r2, [sp, #0x2c]
	ldrb r2, [r2, #0x1e]
	cmp r3, r2
	bge _080AE882
	b _080AE5BE
_080AE882:
	ldr r3, [sp, #0x54]
	cmp r3, #0
	beq _080AE88E
	movs r0, #0xf5
	bl PlaySound_082406e0
_080AE88E:
	add sp, #0x68
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AE8A0: .4byte 0x03003F60
