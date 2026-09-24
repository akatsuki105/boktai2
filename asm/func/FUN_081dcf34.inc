	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _081DCF68 @ =0x0000082A
	adds r4, r7, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _081DCF6C
	subs r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _081DCF5A
	b _081DD060
_081DCF5A:
	adds r0, r7, #0
	movs r1, #0x20
	bl FUN_081dce14
	strh r5, [r4]
	b _081DD060
	.align 2, 0
_081DCF68: .4byte 0x0000082A
_081DCF6C:
	ldr r1, _081DCFB4 @ =0x03004290
	mov sl, r1
	movs r2, #0xf1
	lsls r2, r2, #3
	adds r3, r7, r2
	movs r0, #0xed
	lsls r0, r0, #3
	adds r5, r7, r0
	movs r1, #0
	mov r8, r1
	movs r2, #0xf
	mov sb, r2
	adds r0, #0x60
	adds r6, r7, r0
_081DCF88:
	ldrh r0, [r6]
	ldrh r1, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r6, #0x20]
	ldrh r2, [r3]
	adds r0, r0, r2
	strh r0, [r3]
	ldr r1, _081DCFB8 @ =0x00000808
	adds r0, r7, r1
	add r0, r8
	ldrh r0, [r0]
	ldrh r2, [r3, #0x20]
	adds r0, r0, r2
	strh r0, [r3, #0x20]
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	blt _081DCFBC
	asrs r0, r0, #5
	b _081DCFC2
	.align 2, 0
_081DCFB4: .4byte 0x03004290
_081DCFB8: .4byte 0x00000808
_081DCFBC:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081DCFC2:
	mov ip, r0
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #0
	blt _081DCFD0
	asrs r0, r0, #5
	b _081DCFD6
_081DCFD0:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081DCFD6:
	adds r1, r0, #0
	movs r2, #0x20
	ldrsh r0, [r3, r2]
	cmp r0, #0
	blt _081DCFE4
	asrs r0, r0, #5
	b _081DCFEA
_081DCFE4:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081DCFEA:
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r4, r7, r2
	mov r2, r8
	adds r2, r4, r2
	str r2, [sp]
	lsls r1, r1, #5
	mov r2, ip
	orrs r1, r2
	lsls r0, r0, #0xa
	orrs r0, r1
	ldr r1, [sp]
	strh r0, [r1]
	adds r3, #2
	adds r5, #2
	adds r6, #2
	movs r2, #2
	add r8, r2
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r1, sb
	cmp r1, #0
	bge _081DCF88
	adds r0, r4, #0
	mov r1, sl
	movs r2, #0x10
	bl CpuSet
	ldr r2, _081DD048 @ =0x00000706
	adds r1, r7, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _081DD060
	ldr r1, _081DD04C @ =0x00000828
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _081DD054
	ldr r2, _081DD050 @ =0x0000082A
	adds r1, r7, r2
	movs r0, #0x14
	strh r0, [r1]
	b _081DD05C
	.align 2, 0
_081DD048: .4byte 0x00000706
_081DD04C: .4byte 0x00000828
_081DD050: .4byte 0x0000082A
_081DD054:
	adds r0, r7, #0
	movs r1, #0x20
	bl FUN_081dce14
_081DD05C:
	movs r0, #1
	b _081DD062
_081DD060:
	movs r0, #0
_081DD062:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
