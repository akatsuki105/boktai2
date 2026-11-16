	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, _081E1868 @ =0x030001B0
	str r7, [r0]
	movs r0, #0
	str r0, [r7, #0x18]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetNamedArgValue
	strh r0, [r7, #0x1c]
	adds r0, r7, #0
	adds r0, #0x20
	ldr r1, _081E186C @ =0x00002712
	bl Video_GetAuxSprite
	cmp r0, #0
	bne _081E1870
_081E1860:
	movs r0, #1
	rsbs r0, r0, #0
	b _081E1934
	.align 2, 0
_081E1868: .4byte 0x030001B0
_081E186C: .4byte 0x00002712
_081E1870:
	ldr r0, _081E18E4 @ =0x03002C68
	ldr r0, [r0]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r6, r0, r1
	cmp r0, #0
	bne _081E1880
	movs r6, #0
_081E1880:
	movs r5, #0
	adds r4, r7, #0
	adds r4, #0x6c
_081E1886:
	adds r0, r6, r5
	movs r2, #0
	ldrsb r2, [r0, r2]
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_081e1220
	cmp r0, #0
	blt _081E1860
	adds r4, #0x90
	adds r5, #1
	cmp r5, #4
	ble _081E1886
	movs r5, #0
	ldr r2, _081E18E8 @ =0x03002BE0
	mov r8, r2
	movs r0, #0x5c
	adds r0, r0, r7
	mov ip, r0
_081E18AC:
	lsls r1, r5, #2
	mov r2, r8
	adds r0, r1, r2
	ldr r2, [r0]
	add r1, ip
	str r2, [r1]
	cmp r2, #0
	beq _081E192C
	lsls r0, r5, #3
	adds r3, r0, r7
	adds r3, #0x3c
	adds r6, r2, #0
	adds r6, #0x2c
	ldrh r0, [r2, #0x2c]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081E18EC
	asrs r0, r0, #8
	b _081E18F2
	.align 2, 0
_081E18E4: .4byte 0x03002C68
_081E18E8: .4byte 0x03002BE0
_081E18EC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081E18F2:
	strh r0, [r3]
	adds r1, r4, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081E1904
	asrs r0, r0, #8
	b _081E190A
_081E1904:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081E190A:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _081E191E
	asrs r1, r0, #8
	b _081E1924
_081E191E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_081E1924:
	subs r0, r2, r1
	strh r0, [r3, #2]
	adds r0, r2, r1
	strh r0, [r3, #4]
_081E192C:
	adds r5, #1
	cmp r5, #3
	ble _081E18AC
	movs r0, #0
_081E1934:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
