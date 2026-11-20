	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov ip, r0
	movs r4, #0
	ldr r0, _0801096C @ =0x000002B2
	add r0, ip
	ldrh r1, [r0]
	cmp r4, r1
	bge _0801088C
	movs r6, #0xab
	lsls r6, r6, #2
	add r6, ip
	mov r5, ip
	adds r5, #0x2c
	movs r7, #0
	adds r3, r0, #0
_08010874:
	lsls r2, r4, #1
	ldrh r1, [r6]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r2, r2, r0
	adds r2, r5, r2
	strh r7, [r2]
	adds r4, #1
	ldrh r2, [r3]
	cmp r4, r2
	blt _08010874
_0801088C:
	ldr r0, _0801096C @ =0x000002B2
	add r0, ip
	ldrh r4, [r0]
	movs r0, #0xad
	lsls r0, r0, #2
	mov r8, r0
	mov r0, ip
	add r0, r8
	ldr r1, _08010970 @ =0x000002AE
	add r1, ip
	str r1, [sp]
	movs r2, #0xac
	lsls r2, r2, #2
	add r2, ip
	str r2, [sp, #4]
	ldrh r0, [r0]
	cmp r4, r0
	bge _080108FC
	ldr r0, _08010974 @ =0x0203B400
	mov sl, r0
	ldr r5, _08010978 @ =0x030046B8
	movs r7, #0xab
	lsls r7, r7, #2
	add r7, ip
	ldr r6, _08010970 @ =0x000002AE
	add r6, ip
	ldr r1, _0801097C @ =0x000003FF
	mov sb, r1
_080108C4:
	ldr r0, [r5]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sl
	ldrh r3, [r0]
	lsls r2, r4, #1
	ldrh r1, [r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r2, r2, r0
	mov r1, ip
	adds r1, #0x2c
	adds r1, r1, r2
	movs r2, #0
	ldrsh r0, [r6, r2]
	muls r0, r3, r0
	asrs r0, r0, #0x12
	strh r0, [r1]
	adds r4, #1
	mov r0, ip
	add r0, r8
	ldrh r0, [r0]
	cmp r4, r0
	blt _080108C4
_080108FC:
	movs r0, #0xad
	lsls r0, r0, #2
	add r0, ip
	ldrh r4, [r0]
	cmp r4, #0x9f
	bgt _0801092A
	movs r5, #0xab
	lsls r5, r5, #2
	add r5, ip
	mov r3, ip
	adds r3, #0x2c
	movs r6, #0
_08010914:
	lsls r2, r4, #1
	ldrh r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r2, r2, r0
	adds r2, r3, r2
	strh r6, [r2]
	adds r4, #1
	cmp r4, #0x9f
	ble _08010914
_0801092A:
	movs r0, #0xab
	lsls r0, r0, #2
	add r0, ip
	ldrh r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r0, #0x2c
	add r0, ip
	ldr r1, _08010980 @ =0x03003518
	str r0, [r1]
	ldr r0, _08010984 @ =0x0400004C
	ldr r2, _08010988 @ =0x03002CA0
	str r0, [r2]
	movs r0, #1
	ldr r1, _0801098C @ =0x03003510
	strh r0, [r1]
	ldr r2, _08010990 @ =0x03003514
	strh r0, [r2]
	ldr r1, [sp]
	ldr r2, [sp, #4]
	ldrh r0, [r2]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08010994
	movs r0, #0
	strh r0, [r1]
	b _080109A0
	.align 2, 0
_0801096C: .4byte 0x000002B2
_08010970: .4byte 0x000002AE
_08010974: .4byte 0x0203B400
_08010978: .4byte 0x030046B8
_0801097C: .4byte 0x000003FF
_08010980: .4byte 0x03003518
_08010984: .4byte 0x0400004C
_08010988: .4byte 0x03002CA0
_0801098C: .4byte 0x03003510
_08010990: .4byte 0x03003514
_08010994:
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	ble _080109A0
	ldr r0, [sp]
	strh r1, [r0]
_080109A0:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
