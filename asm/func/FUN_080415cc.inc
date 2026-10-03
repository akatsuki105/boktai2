	push {r4, r5, lr}
	sub sp, #0x10
	mov ip, r0
	adds r5, r3, #0
	cmp r1, #8
	bls _080415DA
	b _080417D2
_080415DA:
	lsls r0, r1, #2
	ldr r1, _080415E4 @ =_080415E8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080415E4: .4byte _080415E8
_080415E8: @ jump table
	.4byte _0804160C @ case 0
	.4byte _0804166A @ case 1
	.4byte _08041644 @ case 2
	.4byte _0804169E @ case 3
	.4byte _080416D4 @ case 4
	.4byte _08041710 @ case 5
	.4byte _08041754 @ case 6
	.4byte _0804177C @ case 7
	.4byte _080417A4 @ case 8
_0804160C:
	movs r0, #0xb1
	lsls r0, r0, #2
	add r0, ip
	movs r2, #0
	str r2, [r0]
	movs r4, #0xb0
	lsls r4, r4, #2
	add r4, ip
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x5c
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #1
	bl FUN_080da9c4
	str r0, [r4]
	ldr r0, _08041640 @ =0x000001B1
	bl PlaySound_082406e0
	b _080417D2
	.align 2, 0
_08041640: .4byte 0x000001B1
_08041644:
	movs r0, #0xb1
	lsls r0, r0, #2
	add r0, ip
	movs r2, #0
	str r2, [r0]
	movs r4, #0xb0
	lsls r4, r4, #2
	add r4, ip
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x5c
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #0
	b _0804168E
_0804166A:
	movs r0, #0xb1
	lsls r0, r0, #2
	add r0, ip
	movs r2, #0
	str r2, [r0]
	movs r4, #0xb0
	lsls r4, r4, #2
	add r4, ip
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x5c
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #3
_0804168E:
	bl FUN_080da9c4
	str r0, [r4]
	movs r0, #0xf6
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080417D2
_0804169E:
	movs r0, #0xb1
	lsls r0, r0, #2
	add r0, ip
	movs r2, #0
	str r2, [r0]
	movs r4, #0xb0
	lsls r4, r4, #2
	add r4, ip
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x5c
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #2
	bl FUN_080da9c4
	str r0, [r4]
	ldr r0, _080416D0 @ =0x000001ED
	bl PlaySound_082406e0
	b _080417D2
	.align 2, 0
_080416D0: .4byte 0x000001ED
_080416D4:
	movs r1, #0xb1
	lsls r1, r1, #2
	add r1, ip
	movs r0, #1
	str r0, [r1]
	movs r3, #0xb2
	lsls r3, r3, #2
	add r3, ip
	movs r4, #0
	strh r2, [r3]
	ldr r2, _0804170C @ =0x000002CA
	add r2, ip
	strh r5, [r2]
	movs r5, #0xb0
	lsls r5, r5, #2
	add r5, ip
	ldr r0, [r5]
	mov r1, ip
	adds r1, #0x5c
	str r3, [sp]
	movs r3, #0
	ldrsh r2, [r2, r3]
	str r2, [sp, #4]
	str r4, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #1
	b _08041746
	.align 2, 0
_0804170C: .4byte 0x000002CA
_08041710:
	movs r1, #0xb1
	lsls r1, r1, #2
	add r1, ip
	movs r0, #3
	str r0, [r1]
	movs r3, #0xb2
	lsls r3, r3, #2
	add r3, ip
	movs r4, #0
	strh r2, [r3]
	ldr r2, _08041750 @ =0x000002CA
	add r2, ip
	strh r5, [r2]
	movs r5, #0xb0
	lsls r5, r5, #2
	add r5, ip
	ldr r0, [r5]
	mov r1, ip
	adds r1, #0x5c
	str r3, [sp]
	movs r3, #0
	ldrsh r2, [r2, r3]
	str r2, [sp, #4]
	str r4, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #3
_08041746:
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r5]
	b _080417D2
	.align 2, 0
_08041750: .4byte 0x000002CA
_08041754:
	movs r1, #0xb1
	lsls r1, r1, #2
	add r1, ip
	movs r0, #5
	str r0, [r1]
	movs r4, #0xb0
	lsls r4, r4, #2
	add r4, ip
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x5c
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #5
	movs r3, #0
	b _080417CC
_0804177C:
	movs r1, #0xb1
	lsls r1, r1, #2
	add r1, ip
	movs r0, #4
	str r0, [r1]
	movs r4, #0xb0
	lsls r4, r4, #2
	add r4, ip
	ldr r0, [r4]
	mov r1, ip
	adds r1, #0x5c
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #4
	movs r3, #0
	b _080417CC
_080417A4:
	movs r4, #0xb0
	lsls r4, r4, #2
	add r4, ip
	ldr r3, [r4]
	cmp r3, #0
	beq _080417D2
	mov r1, ip
	adds r1, #0x5c
	movs r0, #0xb1
	lsls r0, r0, #2
	add r0, ip
	ldrb r2, [r0]
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #0x64
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r3, #0x7f
_080417CC:
	bl FUN_080da9c4
	str r0, [r4]
_080417D2:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
