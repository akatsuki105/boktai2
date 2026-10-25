	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	bl FUN_08022ec0
	movs r0, #0xf6
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _080CA78A
	movs r2, #0x80
	lsls r2, r2, #0xb
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
_080CA78A:
	movs r1, #0x8f
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrh r0, [r2]
	adds r6, r5, #0
	adds r6, #0x98
	cmp r0, #0
	beq _080CA7AA
	movs r0, #0x80
	lsls r0, r0, #0xc
	ldr r1, [r6]
	orrs r1, r0
	str r1, [r6]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
_080CA7AA:
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r1, r5, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080CA7BA
	subs r0, #1
	strh r0, [r1]
_080CA7BA:
	movs r0, #0x80
	lsls r0, r0, #0xe
	ldr r1, [r6]
	ands r0, r1
	cmp r0, #0
	beq _080CA7EC
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r1, r0
	str r1, [r6]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #0
	bl Hitbox_SetPos
	b _080CA7FA
_080CA7EC:
	movs r3, #0x92
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_080CA7FA:
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	bne _080CA820
	movs r0, #0xac
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
_080CA820:
	movs r0, #0x80
	lsls r0, r0, #0xa
	ldr r7, [r6]
	ands r7, r0
	cmp r7, #0
	bne _080CA866
	movs r3, #0xa6
	lsls r3, r3, #2
	adds r4, r5, r3
	ldr r0, _080CA8AC @ =0x000008F3
	adds r6, r5, r0
	ldrb r0, [r6]
	adds r0, #1
	movs r1, #0x98
	muls r1, r0, r1
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r0, r5, r2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080CA866
	strb r7, [r6]
_080CA866:
	movs r3, #0xd4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #0
	bl Hitbox_SetPos
	movs r3, #0xfc
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r2, #0xbe
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #0
	bl Hitbox_SetPos
	ldr r0, _080CA8B0 @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0x2c
	ldrsh r1, [r0, r3]
	movs r2, #0x30
	ldrsh r0, [r0, r2]
	adds r4, r1, r0
	ldr r0, _080CA8B4 @ =0x000005FF
	cmp r4, r0
	bgt _080CA904
	adds r0, #1
	subs r0, r0, r4
	cmp r0, #0
	blt _080CA8B8
	asrs r0, r0, #1
	b _080CA8BE
	.align 2, 0
_080CA8AC: .4byte 0x000008F3
_080CA8B0: .4byte 0x03002BE0
_080CA8B4: .4byte 0x000005FF
_080CA8B8:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080CA8BE:
	adds r4, r0, #0
	ldr r0, _080CA8FC @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x2c]
	ldr r2, [r0, #0x30]
	str r1, [sp]
	str r2, [sp, #4]
	mov r1, sp
	ldrh r2, [r1]
	adds r2, r2, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _080CA900 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r3
	orrs r1, r2
	str r1, [sp]
	mov r1, sp
	ldrh r1, [r1, #4]
	adds r1, r1, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, [sp, #4]
	ands r2, r3
	orrs r2, r1
	str r2, [sp, #4]
	mov r1, sp
	bl FUN_0807a91c
	b _080CA946
	.align 2, 0
_080CA8FC: .4byte 0x03002BE0
_080CA900: .4byte 0xFFFF0000
_080CA904:
	movs r0, #0xe8
	lsls r0, r0, #4
	cmp r4, r0
	ble _080CA946
	ldr r3, _080CA918 @ =0xFFFFF180
	adds r0, r4, r3
	cmp r0, #0
	blt _080CA91C
	asrs r0, r0, #1
	b _080CA922
	.align 2, 0
_080CA918: .4byte 0xFFFFF180
_080CA91C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080CA922:
	adds r4, r0, #0
	ldr r0, _080CA968 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x2c]
	ldr r2, [r0, #0x30]
	str r1, [sp]
	str r2, [sp, #4]
	mov r1, sp
	ldrh r1, [r1]
	subs r1, r1, r4
	mov r2, sp
	strh r1, [r2]
	ldrh r1, [r2, #4]
	subs r1, r1, r4
	strh r1, [r2, #4]
	mov r1, sp
	bl FUN_0807a91c
_080CA946:
	ldr r2, _080CA968 @ =0x03002BE0
	ldr r0, [r2]
	movs r3, #0x30
	ldrsh r1, [r0, r3]
	movs r3, #0x2c
	ldrsh r0, [r0, r3]
	subs r4, r1, r0
	ldr r0, _080CA96C @ =0xFFFFFB80
	adds r7, r2, #0
	cmp r4, r0
	bge _080CA99A
	subs r0, r0, r4
	cmp r0, #0
	blt _080CA970
	asrs r0, r0, #1
	b _080CA976
	.align 2, 0
_080CA968: .4byte 0x03002BE0
_080CA96C: .4byte 0xFFFFFB80
_080CA970:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080CA976:
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, r0, r4
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r1, #4]
	adds r0, r0, r4
	strh r0, [r1, #4]
	ldr r0, [r7]
	bl FUN_0807a91c
	b _080CA9DC
_080CA99A:
	movs r0, #0x90
	lsls r0, r0, #3
	cmp r4, r0
	ble _080CA9DC
	ldr r1, _080CA9B0 @ =0xFFFFFB80
	adds r0, r4, r1
	cmp r0, #0
	blt _080CA9B4
	asrs r0, r0, #1
	b _080CA9BA
	.align 2, 0
_080CA9B0: .4byte 0xFFFFFB80
_080CA9B4:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080CA9BA:
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, r0, r4
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r1, #4]
	subs r0, r0, r4
	strh r0, [r1, #4]
	ldr r0, [r7]
	bl FUN_0807a91c
_080CA9DC:
	ldr r2, _080CAA2C @ =0x0000191C
	adds r0, r5, r2
	movs r6, #0
	movs r1, #0
	strh r1, [r0]
	ldr r3, _080CAA30 @ =0x000025D0
	adds r0, r5, r3
	str r1, [r0]
	adds r0, r5, #0
	adds r0, #0xb4
	str r1, [r0]
	adds r0, #4
	str r1, [r0]
	ldr r0, _080CAA34 @ =0x000025F8
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #1
	bne _080CAACC
	ldr r0, _080CAA38 @ =0x03002BE0
	ldr r3, [r0]
	ldr r1, [r3, #0x1c]
	adds r7, r0, #0
	cmp r1, #4
	beq _080CAAC4
	movs r1, #0x2c
	ldrsh r2, [r3, r1]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xb
	muls r1, r2, r1
	adds r0, r0, r1
	cmp r0, #0
	blt _080CAA3C
	asrs r1, r0, #4
	b _080CAA42
	.align 2, 0
_080CAA2C: .4byte 0x0000191C
_080CAA30: .4byte 0x000025D0
_080CAA34: .4byte 0x000025F8
_080CAA38: .4byte 0x03002BE0
_080CAA3C:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r1, r0, #0
_080CAA42:
	ldr r2, _080CAA68 @ =0x000025F0
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, [r7]
	movs r3, #0x2e
	ldrsh r2, [r0, r3]
	ldr r1, _080CAA6C @ =0x000002EA
	adds r0, r5, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xb
	muls r1, r2, r1
	adds r0, r0, r1
	cmp r0, #0
	blt _080CAA70
	asrs r1, r0, #4
	b _080CAA76
	.align 2, 0
_080CAA68: .4byte 0x000025F0
_080CAA6C: .4byte 0x000002EA
_080CAA70:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r1, r0, #0
_080CAA76:
	ldr r2, _080CAAA0 @ =0x000025F2
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, [r7]
	movs r3, #0x30
	ldrsh r2, [r0, r3]
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xb
	muls r1, r2, r1
	adds r0, r0, r1
	cmp r0, #0
	blt _080CAAA4
	asrs r2, r0, #4
	b _080CAAAA
	.align 2, 0
_080CAAA0: .4byte 0x000025F2
_080CAAA4:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r2, r0, #0
_080CAAAA:
	ldr r1, _080CAABC @ =0x000025F4
	adds r0, r5, r1
	strh r2, [r0]
	ldr r2, _080CAAC0 @ =0x000025F0
	adds r0, r5, r2
	bl Camera_MoveTo
	b _080CAB20
	.align 2, 0
_080CAABC: .4byte 0x000025F4
_080CAAC0: .4byte 0x000025F0
_080CAAC4:
	movs r0, #8
	bl FUN_0823b880
	b _080CAB1E
_080CAACC:
	cmp r0, #2
	bne _080CAAFC
	ldr r3, _080CAAF0 @ =0x000025F0
	adds r1, r5, r3
	movs r3, #0x80
	lsls r3, r3, #3
	strh r3, [r1]
	ldr r0, _080CAAF4 @ =0x000025F2
	adds r2, r5, r0
	movs r0, #0xa8
	lsls r0, r0, #1
	strh r0, [r2]
	ldr r2, _080CAAF8 @ =0x000025F4
	adds r0, r5, r2
	strh r3, [r0]
	movs r0, #8
	b _080CAB1A
	.align 2, 0
_080CAAF0: .4byte 0x000025F0
_080CAAF4: .4byte 0x000025F2
_080CAAF8: .4byte 0x000025F4
_080CAAFC:
	cmp r0, #3
	bne _080CAB20
	ldr r3, _080CAB30 @ =0x000025F0
	adds r1, r5, r3
	ldr r3, _080CAB34 @ =0x00000504
	strh r3, [r1]
	ldr r0, _080CAB38 @ =0x000025F2
	adds r2, r5, r0
	movs r0, #0xa8
	lsls r0, r0, #1
	strh r0, [r2]
	ldr r2, _080CAB3C @ =0x000025F4
	adds r0, r5, r2
	strh r3, [r0]
	movs r0, #0x10
_080CAB1A:
	bl FUN_0823b980
_080CAB1E:
	strb r6, [r4]
_080CAB20:
	adds r0, r5, #0
	bl FUN_080c2b24
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CAB30: .4byte 0x000025F0
_080CAB34: .4byte 0x00000504
_080CAB38: .4byte 0x000025F2
_080CAB3C: .4byte 0x000025F4
