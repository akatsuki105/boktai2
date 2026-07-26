	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x34
	mov r8, r0
	bl FUN_082345ec
	mov r0, sp
	movs r1, #0x2c
	bl FUN_082309cc
	bl fetch_082316e4
	mov r1, sp
	strh r0, [r1, #8]
	bl fetch_082316e4
	mov r1, sp
	strh r0, [r1, #6]
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _0823AFA8
	bl fetch_082316e4
	mov r1, sp
	b _0823AFAC
_0823AFA8:
	mov r1, sp
	ldr r0, _0823AFDC @ =0x00000DD2
_0823AFAC:
	strh r0, [r1, #4]
	movs r0, #0x74
	movs r1, #0
	bl FUN_0823174c
	mov r1, sp
	movs r3, #0
	movs r2, #0
	strh r0, [r1, #0xa]
	mov r0, sp
	strh r2, [r0, #0xc]
	ldrh r0, [r0, #6]
	cmp r0, #0x3f
	bne _0823AFCC
	ldr r0, _0823AFE0 @ =0x000014C9
	strh r0, [r1, #6]
_0823AFCC:
	mov r0, sp
	ldrh r0, [r0, #4]
	cmp r0, #0x3f
	bne _0823AFE4
	mov r1, sp
	ldr r0, _0823AFE0 @ =0x000014C9
	b _0823AFEC
	.align 2, 0
_0823AFDC: .4byte 0x00000DD2
_0823AFE0: .4byte 0x000014C9
_0823AFE4:
	cmp r0, #0x2a
	bne _0823AFEE
	mov r1, sp
	ldr r0, _0823B014 @ =0x00001516
_0823AFEC:
	strh r0, [r1, #4]
_0823AFEE:
	add r4, sp, #0x10
	add r6, sp, #0x18
	mov r7, sp
	adds r7, #0xe
	adds r2, r4, #0
	movs r1, #0
	mov r0, sp
	adds r0, #0x16
_0823AFFE:
	strh r1, [r0]
	subs r0, #2
	cmp r0, r2
	bge _0823AFFE
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _0823B02E
	movs r5, #0
	b _0823B022
	.align 2, 0
_0823B014: .4byte 0x00001516
_0823B018:
	bl FUN_082315a4
	strh r0, [r4]
	adds r4, #2
	adds r5, #1
_0823B022:
	cmp r5, #3
	bgt _0823B02E
	bl FUN_082316bc
	cmp r0, #0
	bne _0823B018
_0823B02E:
	adds r1, r6, #0
	movs r2, #0
	adds r0, r6, #6
_0823B034:
	strh r2, [r0]
	subs r0, #2
	cmp r0, r1
	bge _0823B034
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _0823B062
	movs r5, #0
	adds r4, r6, #0
	b _0823B056
_0823B04C:
	bl FUN_082315a4
	strh r0, [r4]
	adds r4, #2
	adds r5, #1
_0823B056:
	cmp r5, #3
	bgt _0823B062
	bl FUN_082316bc
	cmp r0, #0
	bne _0823B04C
_0823B062:
	movs r0, #0x62
	bl prepare_08231510
	cmp r0, #0
	beq _0823B07E
	mov r2, sp
	mov r0, sp
	ldrh r1, [r0, #0xc]
	movs r0, #0x10
	orrs r0, r1
	strh r0, [r2, #0xc]
	bl fetch_082316e4
	str r0, [sp, #0x20]
_0823B07E:
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _0823B098
	bl FUN_082316bc
	add r1, sp, #0x2c
	add r2, sp, #0x30
	bl VM_Step
	ldr r0, [sp, #0x30]
	b _0823B0B2
_0823B098:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0823B0B4
	mov r2, sp
	mov r0, sp
	ldrh r1, [r0, #0xc]
	movs r0, #0x20
	orrs r0, r1
	strh r0, [r2, #0xc]
	bl fetch_082316e4
_0823B0B2:
	str r0, [sp, #0x24]
_0823B0B4:
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0, #0xc]
	movs r1, #0
	strh r0, [r2, #0xc]
	mov r0, sp
	strh r1, [r0, #0xe]
	ldrh r0, [r0, #8]
	adds r1, r7, #0
	bl FUN_0823492c
	str r0, [sp, #0x28]
	cmp r0, #0
	beq _0823B0DC
	mov r0, sp
	mov r1, r8
	bl FUN_082349b8
	movs r0, #0
	b _0823B0E0
_0823B0DC:
	movs r0, #1
	rsbs r0, r0, #0
_0823B0E0:
	add sp, #0x34
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
